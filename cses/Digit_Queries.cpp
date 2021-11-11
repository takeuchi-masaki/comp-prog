#include <bits/stdc++.h>
using namespace std;

int getDigit(long long num, int digit){
    // from most significant first
    string n = to_string(num);
    return *(n.end()-digit-1) - '0';
}

void solve(){
    long long k; cin >> k;
    long long total = 0, mult1 = 9, mult2 = 1;
    while(true){
        long long next = total + mult1 * mult2;
        if(next >= k) break;
        total = next;
        // cout << total << '\n';
        mult1 *= 10;
        mult2++;
    }
    // previous = total
    // (n - total) / mult2
    mult1 /= 10;
    long long diff = k - total;
    long long num = (diff + mult2 - 1) / mult2 + total;
    long long digit = diff % mult2;
    cout << k << ' ' << num << ' ' << digit << '\n';
    cout << getDigit(num, digit) << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}