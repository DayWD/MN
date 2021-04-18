//Dawid Urbanik
#include "vectalg.h"
using namespace std;


Vector Matrix_Norms(const Matrix &A)
{
    Vector norms(A.size());

    for(double i:norms)
        norms[i]=0;

    for(int i = 0;i<A.size();i++)
    {
        for(int k = 0;k<A.size();k++)
        {
            if(abs(A(i,k)) >norms[i])
            norms[i]= abs(A(i,k));
        }
    }
    return norms;
}

int Select_Pivot(const Vector &column,const Vector &norms)
{
    int pivot;
    double temp;
    double max = 0;
    int i = 0;

    for(;i<norms.size();i++)
    {
        temp = column[i]/norms[i];

        if(max < temp)
            pivot = i;
    }
    return pivot;
}

void Swap_Rows(const int &pivot,Matrix &A, const int &iteration, Vector &B)
{
    Vector temp(A.size());

    double temp_B = B[0];
    B[0] = B[pivot];
    B[pivot] = temp_B;

    for (int i = 0;i<A.size();i++)
        temp[i] = A(iteration, i);

    for (int i = 0;i<A.size();i++)
    {
        A(iteration,i) = A(pivot,i);
        A(pivot,i) = temp[i];
    }
}

void Modify_row_under_i_row(const int i, Matrix &G, Vector &B)
{
    for (int next_row = i+1;next_row<G.size();next_row++)
    {
        double temp = G(next_row,i)/G(i,i);

        for(int k = 1;k<G.size();k++)
        {
            G(next_row,k) -= temp * G(i,k);
        }

        B[next_row] -= temp * B[i];
    }
}

Vector solveEquations(
        const Matrix & A,   // Macierz
        const Vector & b,   // Wektor
        double  eps         // dopuszczalny błąd
)
{
    int pivot;
    Vector norms = Matrix_Norms(A);
    Vector next_colum(A.size());
    Matrix G(A);
    Vector B(b);

    for(int i = 0;i<A.size() - 1;i++)   //  steps of gaussian elimination
    {
        for(int k = 0;k<A.size();k++)
            next_colum[k] = abs(A(i,k));     // needed to calculate which number in column will be pivot

        cout<< next_colum<<endl<<norms<<endl<<endl;
        pivot = Select_Pivot(next_colum,norms); //  row number which will be on 0 row index after swap

        if(pivot != 0)  // swap rows
            Swap_Rows(pivot,G,i,B);

        Modify_row_under_i_row(i,G,B);

    }
    cout<<G<<endl;
    cout<<B<<endl;

    return b;
}

/**
3
2 1 2
2 -1 3
4 6 4
-2
-5
4
1e-15
 */

/**
2
1 1
1 -1
1
1
1e-15
 */

