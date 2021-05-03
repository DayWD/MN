//Dawid Urbanik
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout.precision(16);
    int n,m;
    cin>>n>>m;
    double temp;
    vector<double> A[m];

    int flag = 0;
    int index = 0;

    // matrix initialization
    for(int k=n-m/2;k>n-m/2-1;)
    {
        if(k<n and flag==0)
        {
            A[index].push_back(n-k);
            for(int i = 0;i<k;i++)
            {
                cin>>temp;
                A[index].push_back(temp);
            }
            k++;
        }
        else if(k==n || flag==1)
        {
            A[index].push_back(n-k);
            for(int i = 0;i<k;i++)
            {
                cin>>temp;
                A[index].push_back(temp);
            }
            k--;
            flag=1;
        }
        index++;
    }

    // vector initialization
    double y[n];
    double x[n];

    for(int i=0;i<n;i++)
        cin>>y[i];

    for(int i=0;i<n;i++)
        cin>>x[i];

    double w;
    cin>>w;

    int L;
    cin>>L;

    double s;

    //  Algorythm for calculating x from Ax=y equation using band matrix A having diagonal bands in array of vectors.
    for(int iter=0; iter < L; iter++) {
        for (int i = 0; i < n; i++) {
            s = y[i];

            for(int k=0;k<m/2;k++)
            {
                if(n-A[k][0]>i)
                {
                    s -= A[k][i+1] * x[i+ static_cast<int>(A[k][0])];
                }
            }

            for(int k=m/2+1;k<m;k++)
            {
                if(A[k][0]<=i)
                {
                    s -= A[k][i+1 - A[k][0]] * x[i-static_cast<int>(A[k][0])];
                }
            }
            x[i] = (1-w) * x[i] + w* s / A[m/2][i+1];
        }
    }

    for(int k=0;k<n;k++)
        cout<<x[k]<<" ";

    return 0;
}