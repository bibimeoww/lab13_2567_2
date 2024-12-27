#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);
void stat(const double A[], int N, double B[]){
    B[0] = A[0];
    B[1] = A[0]*A[0];
    B[2] = A[0];
    B[3] = 1.0/A[0];
    B[4] = A[0];
    B[5] = A[0];
    for(int i =1; i < N; i++){
        B[0] += A[i];
        B[1] += A[i]*A[i];
        B[2] *= A[i];
        B[3] += 1.0/A[i];
        if (A[i] > B[4]){
            B[4] = A[i];
        }
        if (A[i] < B[5]){
            B[5] = A[i];
        }
    }
    B[0] /= N;
    B[1] = sqrt((1.0/N * B[1]) - (B[0] * B[0]));
    B[2] = pow(B[2] , 1.0 / N);
    B[3] = N / B[3];
}
int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}