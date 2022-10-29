#include <iostream>
#include <math.h>

using std::cin, std::cout;


double F(double A, double B, double p){
    return A - B * p;
}


int main(){
    double A, B, P, L, R;
    
    cout << "Делимое: ";
    cin >> A;

    cout << "\nДелитель: ";
    cin >> B;

    L = 0;
    R = A;

    while(R - L > 0.0001) {
        P = (L + R) / 2;

        if(F(A, B, P) * F(A, B, R) > 0) {
            R = P;
        }
        else {
            L = P;
        }
    }

    cout << "\nПолученное значение: " << P;

    P = std::floor(P);
    cout << "\nЦелое: " << P;
    cout << "\nОстаток: " << A - B * P << '\n';
}