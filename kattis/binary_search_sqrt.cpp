#include <bits/stdc++.h>
using namespace std;

/**
    @num number to find square-root
    @returns square root
*/ 
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
    // accurate up to "precision"
    double precision = 1e-6; // 0.000001

    // 1.4142141 vs actual value 1.41421356237
    cout << setprecision(8) << bin_sqrt(2, precision) << '\n'; 

    // 1.4142136 vs actual value 1.41421356237
    cout << bin_sqrt(2, precision/10) << '\n';

    cout << bin_sqrt(4, precision) << '\n';
}