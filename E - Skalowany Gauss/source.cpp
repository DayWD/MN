//Dawid Urbanik
#include "vectalg.h"

using namespace std;

Vector Matrix_Norms(const Matrix &A)
{
    Vector norms(A.size());

    for (double &i:norms)
        i = 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int k = 0; k < A.size(); k++)
        {
            if (abs(A(i, k)) > norms[i])
                norms[i] = abs(A(i, k));
        }
    }
    return norms;
}

int Select_Pivot(const Matrix &G, const Vector &norms, const int &iteration)
{
    int pivot = iteration;
    double temp;
    double max = 0;
    int i = iteration;

    for (; i < norms.size(); i++)
    {
        temp = abs(G(i, iteration)) / norms[i];

        if (max < temp)
        {
            max = temp;
            pivot = i;
        }
    }
    return pivot;
}

void Swap_Rows(const int &pivot, Matrix &A, const int &iteration, Vector &B)
{
    Vector temp(A.size());

    double temp_B = B[iteration];
    B[iteration] = B[pivot];
    B[pivot] = temp_B;

    for (int i = 0; i < A.size(); i++)
        temp[i] = A(iteration, i);

    for (int i = 0; i < A.size(); i++)
    {
        A(iteration, i) = A(pivot, i);
        A(pivot, i) = temp[i];
    }
}

void Modify_row_under_i_row(const int i, Matrix &G, Vector &B)
{
    double temp;

    for (int next_row = i + 1; next_row < G.size(); next_row++)
    {
        temp = G(next_row, i) / G(i, i);

        for (int k = 0; k < G.size(); k++)
            G(next_row, k) -= temp * G(i, k);

        B[next_row] -= temp * B[i];
    }
}

void Calculate_Solution(Vector &X, Vector &B, Matrix &G)
{
    for (int i = X.size() - 1; i >= 0; i--)
    {
        X[i] = B[i];

        for (int j = i + 1; j < G.size(); j++)
        {
            X[i] -= G(i, j) * X[j];
        }
        X[i] = X[i] / G(i, i);
    }
}

Vector solveEquations(
        const Matrix &A,   // Macierz
        const Vector &b,   // Wektor
        double eps         // dopuszczalny blad
)
{
    int pivot;
    Vector norms = Matrix_Norms(A);
    Vector next_colum(A.size());
    Matrix G(A);
    Vector B(b);

    for (int i = 0; i < A.size() - 1; i++)   //  steps of gaussian elimination
    {

        pivot = Select_Pivot(G, norms, i); //  row number which will be on 0 row index after swap

        if (pivot != i)  // swap rows
            Swap_Rows(pivot, G, i, B);

        Modify_row_under_i_row(i, G, B);
    }

    Vector X(b.size());

    Calculate_Solution(X, B, G);

    Vector residual = residual_vector(A, b, X);
    Vector e;


    //! Iterative Improvement
    if (residual.max_norm() >= eps)
    {
        residual = residual_vector(A, b, X);
        e = solveEquations(A, residual, eps);

        for (int i = 0; i < X.size(); i++)
        {
            X[i] += e[i];
        }
    }
    return X;
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


/**
5
-1 2 -3 3 5
8 0 7 4 -1
-3 4 -3 2 -2
8 -3 -2 1 2
-2 -1 -6 9 0
56
62
-10
14
28
1e-15
 */