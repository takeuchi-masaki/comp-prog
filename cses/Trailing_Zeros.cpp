#include <bits/stdc++.h>
using namespace std;

int logbaseX(int num, int x){
    int cnt = 0;
    while(num > 0){
        cnt += num/5;
        num /= x;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cout << logbaseX(n, 5) << '\n';
}