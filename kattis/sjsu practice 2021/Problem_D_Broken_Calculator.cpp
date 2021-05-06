#include <bits/stdc++.h>
using namespace std;

long long prevAns = 1;

void add(long long a, long long b){
    long long res = a+b - prevAns;
    cout << res << endl;
    prevAns = res;
}

void subtr(long long a, long long b){
    long long res = a-b;
    res*=prevAns;
    cout << res << endl;
    prevAns = res;
}

void mult(long long a, long long b){
    long long res = a*b;
    res*=res;
    cout << res << endl;
    prevAns = res;
}

void divide(long long a, long long b){
    long long res = (a+1)/2;
    cout << res << endl;
    prevAns = res;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        long long a, b; char op;
        cin >> a >> op >> b;
        // cout << a << ' ' << op << ' ' << b << endl;
        switch(op){
            case '+':
                add(a, b);
                break;
            case '-':
                subtr(a, b);
                break;
            case '/':
                divide(a, b);
                break;
            case '*':
                mult(a, b);
                break;
        }
    }
}