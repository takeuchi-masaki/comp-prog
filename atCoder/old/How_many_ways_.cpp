#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n, x;
        cin >> n >> x;
        if(n==0 && x==0) break;
        int count = 0;
        for(int i = 1; i <= n-2; i++){
            for(int j = i+1; j <= n-1; j++){
                int k = x-i-j;
                if(k>j && k<=n) count++;
            }
        }
        cout << count << '\n';
    }
}