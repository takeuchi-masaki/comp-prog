#include <bits/stdc++.h>
using namespace std;

double bin_sqrt(int num, double precision){
    double bad = 0, ok = num;
    while(abs(ok - bad) > precision){
        double mid = (bad + ok) / 2;
        if(mid * mid >= num) ok = mid;
        else bad = mid;
    }
    return ok;
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