#include <bits/stdc++.h>
using namespace std;

long long solve(){
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> presses(l);
    for(int i = 0; i < l; i++){
        cin >> presses[i];
    }
    sort(presses.begin(), presses.end(), greater<int>());
    long long ans = 0, cnt = 0, curr = 1;
    for(int i : presses){
        ans += curr*i;
        cnt++;
        if(cnt==k){
            cnt = 0;
            curr++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        cout << solve() << endl;
    }
}