#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
vector<int> pow9;

int rainbow_cnt(string& s){
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + pow9[i]) % MOD;
    }



    return ans;
}

void calcPow9(){
    pow9.resize(100001);
    pow9[0] = 1;
    for(int i = 1; i < pow9.size(); i++){
        pow9[i] = (pow9[i - 1] * 9) % MOD;
    }
}

bool is_rainbow(string& s){
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i+1]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string low, high; cin >> low >> high;
    int ans = rainbow_cnt(high) - rainbow_cnt(low) + is_rainbow(low);
    if(ans < 0) ans += MOD;
    else ans %= MOD;
    cout << ans << '\n';
}