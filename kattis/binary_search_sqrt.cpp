#include <bits/stdc++.h>
using namespace std;

double bin_sqrt(int num, double precision){
    double left = 0, right = num;
    while(right - left > precision){
        double mid = left + (right-left)/2;
        if(mid*mid >= num) right = mid;
        else left = mid;
    }
    return right;
}

int main(){
    double precision = 1e-6; // 0.000001

    // 1.4142141 
    // 1.41421356237 vs actual value
    cout << setprecision(8) << bin_sqrt(2, precision) << '\n'; 

    // 1.4142136
    // 1.41421356237 vs actual value
    cout << bin_sqrt(2, precision/10) << '\n';

    cout << bin_sqrt(4, precision) << '\n';
}