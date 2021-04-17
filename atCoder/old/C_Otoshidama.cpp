#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, y;
    cin >> n >> y;
    const int sen = 1000, gosen = 5000, man = 10000;
    bool ok = false;
    int a = -1, b=-1, c=-1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j+i<=n; j++){
            int k = n-i-j;
            if((long)man*i+gosen*j+sen*k==y){
                a=i,b=j,c=k;
                break;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
}