/*
ID: themasa1
TASK: frac1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

class Fraction{
    public:
    int num, den;
    Fraction(int numerator, int denominator){
        num = numerator;
        den = denominator;
    }
};

bool FractionCompare(const Fraction & f1, const Fraction & f2){
    double f1Val = (double)f1.num/f1.den;
    double f2Val = (double)f2.num/f2.den;
    return f1Val < f2Val;
}

bool notSimple(int a, int b){
    return __gcd(a, b)!=1;
}

int main() {
    freopen("frac1.in","r",stdin); freopen("frac1.out","w",stdout);
    int n; cin >> n;
    vector<Fraction> v;
    v.push_back(Fraction(0,1));
    v.push_back(Fraction(1,1));
    for(int num = 1; num < n; num++){
        for(int den = num+1; den <= n; den++){
            if(notSimple(num, den)) continue;
            v.push_back(Fraction(num, den));
        }
    }
    sort(v.begin(), v.end(), FractionCompare);
    for(Fraction f:v){
        cout << f.num << '/' << f.den << '\n';
    }
    return 0;
}