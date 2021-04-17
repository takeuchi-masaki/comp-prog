#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    cin >> x;
    int digits = 0;
    long long copy = x;
    while(copy>0){
        digits++;
        copy/=10;
    }
    // cout << digits << endl;
    long long estimate = 0;
    long long mult = 1;
    for(int i = 0; i < digits; i++){
        mult = 1;
        for(int j = 0; j < i; j++){
            mult*=10;
        }
        estimate+=mult*9;
    }
    // cout << estimate << endl;
    while(estimate > x){
        estimate -= mult;
        if(estimate <= 0){
            estimate = 0;
            for(int i = 0; i < digits-1; i++){
                mult = 1;
                for(int j = 1; j < digits-1; j++){
                    mult*=10;
                }
                estimate+=mult*9;
            }
        }
    }
    int res = 0;
    while(estimate > 0){
        res+=estimate%10;
        estimate/=10;
    }
    cout << res << endl;
}