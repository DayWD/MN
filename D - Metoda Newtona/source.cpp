//Dawid Urbanik
using namespace std;

void printVector(const double* x, unsigned N){
    for(unsigned i=0;i<N;++i)
        printf("%17.17f ",x[i]);
    printf("\n");
}
//      x - tablica długości N, określająca wektor, dla którego liczona jest wartość funkcji
//      y - tablica długości M, do której funkcja wpisze obliczone f(x). Funkcja zakłada, że tablica y ma co najmniej M elementów!
//      Df - tablica długości M*N, do której funkcja wpisze obliczoną macierz różniczki Df(x). Funkcja zakłada, że tablica Df ma co najmniej N*M elementów!

typedef void (*FuncPointer)(const double* x, double* y, double* Df);


//        f - wskaźnik do funkcji R3 -> R2
//        x - tablica liczb double długości 3, zawierająca punkt początkowy bliski miejsca zerowego funkcji (czyli f(x)≈(0,0))
//        k - określa liczbę punktów do wyznaczenia
//        h - krok zmiany parametru. Funkcję f możemy traktować jako   f(a,b,c) = (f1(a,b,c),f2(a,b,c))

double* Matrix_Inversion_2x2(double a,double b,double c,double d)
{
    double det = (a*d-b*c);
    static double M[4] = {d/det,-b/det,-c/det,a/det};
    return M;
}

int findCurve(FuncPointer f, double* x, unsigned k, double h)
{
    cout.precision(17);
    double Df[6];
    double *Dfc;
    double M_temp[2];

    for(int i=1;i<=k;i++) {
        double y[2]={1};
        double next_iter[3]={x[0],x[1],x[2]+i*h};
        while (abs(y[0]) >= pow(10, -13) || abs(y[1]) >= pow(10, -13)) {
            f(next_iter, y, Df);
            Dfc = Matrix_Inversion_2x2(Df[0], Df[1], Df[3], Df[4]);
            M_temp[0] = Dfc[0] * y[0] + Dfc[1] * y[1];
            M_temp[1] = Dfc[2] * y[0] + Dfc[3] * y[1];
            next_iter[0] = next_iter[0] - M_temp[0];
            next_iter[1] = next_iter[1] - M_temp[1];
        }
//    printVector(next_iter,3);
        cout << next_iter[0] << "  " << next_iter[1] << "  " << next_iter[2] << endl;
    }

    return 0;
}