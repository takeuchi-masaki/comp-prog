#include <bits/stdc++.h>
using namespace std;

bool check7_1(int num){
    while(num>0){
        if(num%10==7) return true;
        num/=10;
    }
    return false;
}

bool check7_2(int num){
    while(num>0){
        if(num%8==7) return true;
        num/=8;
    }
    return false;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!check7_1(i) && !check7_2(i)){
            res++;
        }
    }
    cout << res << '\n';
}