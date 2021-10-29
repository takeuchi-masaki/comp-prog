#include <bits/stdc++.h>
using namespace std;

long long val(int diff){
    long long ans = 0, add = 9;
    while(diff--){
        ans += add;
        add *= 10;
    }
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long note_count = 0, currVal = 0;
    for(int i = 0; i < n-1; i++){
        long long curr = val(a[i+1]-a[i]);
        if(note_count + curr > k){
            long long diff = k-note_count +1;
            note_count += diff;
            currVal += powl(10, a[i])*diff;
            break;
        } else {
            note_count += curr;
            currVal += powl(10, a[i])*curr;
        }
    }
    // cout << k << ' ' << note_count << '\n';
    if(k-note_count >= 0){
        long long diff = k-note_count +1;
        currVal += powl(10, a[n-1])*diff;
    }
    cout << currVal << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        solve();
    }
}