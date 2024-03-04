#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double z(double x1, double x2) {
    return pow(x1, 2) + 3 * pow(x2, 2);
}

double g1(double x1, double x2) {
    return -x2 - 3 * pow(x1, 2) + 2;
}

double g2(double x1, double x2) {
    return x2 + x1 - 1;
}

int main() {
    setlocale(LC_ALL, "russian");

    double x1a, x1b, x2a, x2b, h, minz=0;
    int r = 0, t = 0, m = 0;

    cout<<"x1a=";
    cin>>x1a;

    cout<<"x1b=";
    cin>>x1b;

    cout<<"x2a=";
    cin>>x2a;

    cout<<"x2b=";
    cin>>x2b;

    cout<<"h=";
    cin>>h;

    int n1 = sqrt(pow((x1b - x1a), 2))/h;
    int n2 = sqrt(pow((x2b - x2a), 2))/h;

    double* x1 = new double [n1];
    
    for (int i=0; i < n1; i++) {
        x1[i] = x1a + i*h;
    }

    double* x2 = new double[n2];

    for (int j= 0; j < n2; j++) {
        x2[j] = x2a + j * h;
    }

    double** l = new double* [n1];

    for (int i=0; i<n1; i++) {
        l[i] = new double[n2];
    }

    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            l[i][j] = '\0';
        }
    }

    int k = 1;

    for (int j=0; j < n2; j++) {
        if (k==1) {
            cout<<"";
        }
        k = 2;
        cout<<right<<setw(7)<<x2 [j]<<"|";
    }

    cout<<endl;

    for (int i=0; i<n1; i++) {
        for (int j=0; j<n2; j++) {
            if (g1(x1[i],x2[j]) >= 0 and g2(x1[i], x2[j]) >=0) {
                l[i][j] = z(x1[i], x2[j]);
                if (m<1) {
                    minz = l[i][j];
                    m=m+1;
                }
                if (minz<l[i][j]) {
                    minz = l[i][j];
                    r=i;
                    t=j;
                }
                cout<<right<<setw(7)<<setprecision(2)<<fixed<<l[i][j]<<"|";
            } else {
                cout<<right<<setw(7)<<"|"<<"1";
            }
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"minz="<<minz<<'\t'<<"x1="<<x1[r]<<'\t'<<"x2="<<x2[t]<<endl;

    delete[] x1;
    delete[] x2;

    for (int i=0; i<n1; i++) {
        delete[]l[i];
    }

    delete[] l;
    system("pause");
    return 0;
}