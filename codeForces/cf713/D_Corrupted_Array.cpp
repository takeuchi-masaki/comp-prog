#include <bits/stdc++.h>
using namespace std;

void ans(vector<int>& a, int ignore1, int ignore2){
    for(int i = 0; i < a.size(); i++){
        if(i==ignore1 || i==ignore2) continue;
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void solve(){
    int n; cin >> n;
    vector<int> a(n+2);
    for(int i = 0; i < n+2; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long biggest = a[n+1], big2 = a[n];
    long long sum = 0;
    map<long long, int> m;
    for(int i = 0; i < n; i++){
        sum+=a[i];
        m[a[i]]++;
    }
    // case: x is largest
    if(sum == big2){
        // cout << "x ";
        ans(a, n, n+1);
        return;
    }
    // case: sum is largest
    sum+=big2;
    m[big2]++;
    long long findNum = sum-biggest;
    // cout << "findSum " << findNum << '\n';
    if(m.count(findNum)){
        // cout << "a ";
        int ignore = lower_bound(a.begin(), a.end(), findNum) - a.begin();
        ans(a, ignore, n+1);
        return;
    }
    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}