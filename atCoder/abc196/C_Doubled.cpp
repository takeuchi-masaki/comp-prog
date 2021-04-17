#include <bits/stdc++.h>
using namespace std;

long long n;

bool ok(int num){
    string check = to_string(num) + to_string(num);
    if(stoll(check)<=n) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    // check all possible values
    const int MAX = 1E6;
    long long res = 0;
    for(int i = 0; i < MAX; i++){
        if(ok(i)) res++;
        else break;
    }
    cout << res-1 << endl;
    return 0;
}