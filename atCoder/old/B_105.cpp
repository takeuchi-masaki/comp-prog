#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i+=2){
        int div = 0;
        for(int j = 1; j <= i; j++){
            if(i%j==0) div++;
        }
        if(div==8) res++;
    }
    cout << res << endl;
}