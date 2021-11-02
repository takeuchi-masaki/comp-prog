#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int&i : a) cin >> i;
    int count = 0;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[minIndex]) minIndex = j;
        }
        // shift j to i
        int shift = minIndex-i;
        if(shift == 0) continue;
        count++;
        // cout << i+1 << ' ' << minIndex+1 << ' ' << shift << '\n';
        vp.push_back(make_pair(i, minIndex));
        vector<int> temp(n);
        for(int j = i; j <= minIndex; j++){
            int right = j+shift;
            if(right > minIndex) right = shift - (minIndex+1-j) + i;
            temp[j] = a[right];
        }
        for(int j = i; j <= minIndex; j++){
            a[j] = temp[j];
        }
        // for(int i:a) cout << i << ' ';
        // cout << '\n';
    }
    cout << count << '\n';
    for(auto p:vp){
        cout << p.first+1 << ' ' << p.second+1 << ' ' << p.second-p.first << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}