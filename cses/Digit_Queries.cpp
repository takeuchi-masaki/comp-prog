#include <bits/stdc++.h>
using namespace std;

vector<long long> DIGIT;

void solve(){
    long long n; cin >> n;
    auto lb = lower_bound(DIGIT.begin(), DIGIT.end(), n);
    int digits = lb - DIGIT.begin();
    long long pow10 = 1;
    for(int i = 0; i < digits; i++) pow10 *= 10;
    pow10--;
    long long cnt = (*lb - n) / digits, rem = (*lb - n) % digits;
    long long curr = pow10 - cnt;
    cout << to_string(curr)[digits - 1 - rem] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin.exceptions(cin.failbit);

    DIGIT.push_back(0);
    const long long MX = 1e18;
    long long cumu = 0, pow10 = 1;
    int digitLen = 1;
    while(cumu < MX){
        cumu += digitLen * 9 * pow10;
        DIGIT.push_back(cumu);
        digitLen++;
        pow10 *= 10;
    }

    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}