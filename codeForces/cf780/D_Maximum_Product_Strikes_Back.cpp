#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    vector<int> zero;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) zero.push_back(i);
    }
    zero.push_back(n);

    int best_sum = 0, idx = 0;
    int L = -1, R = -1;
    for(int z : zero){
        int cnt_2 = 0, parity = 0;
        int first_negative = -1, last_negative = -1;
        for(int i = idx; i < z; i++){
            cnt_2 += (abs(a[i]) == 2);
            if(a[i] < 0){
                parity ^= 1;
                if(first_negative == -1) first_negative = i;
                last_negative = i;
            }
        }
        int l = idx, r = z-1;
        if(parity){
            int sum1 = cnt_2, sum2 = cnt_2;
            for(int i = idx; i <= first_negative; i++){
                sum1 -= (abs(a[i]) == 2);
            }
            for(int i = z - 1; i >= last_negative; i--){
                sum2 -= (abs(a[i]) == 2);
            }
            cnt_2 = max(sum1, sum2);
            if(sum1 > sum2){
                l = first_negative + 1;
            } else {
                r = last_negative - 1;
            }
        }
        // cout << cnt_2 << '\n';
        if(cnt_2 > best_sum){
            best_sum = cnt_2;
            L = l, R = r;
        }
        idx = z + 1;
    }
    if(L == -1){
        cout << n << " 0\n";
        return;
    }
    // cout << "a: " << L << ' ' << R << '\n';
    cout << L << ' ' << n - 1 - R << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}