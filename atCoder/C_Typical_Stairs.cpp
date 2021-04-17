#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

vector<int> st(1e5+1,-1);
int staircase(int steps){
    if(st[steps]!=-1) return st[steps];
    long long res = staircase(steps-2) + staircase(steps-1);
    res%=mod;
    return st[steps] = res;
}

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m; // n steps, m broken
    vector<bool> broken(n+1, false);
    for(int i = 0; i < m; i++){
        int step; cin >> step;
        broken[step]=true;
    }
    st[0]=1, st[1]=1;
    // for(int i = 0; i < 10; i++){
    //     cout << i << " " << staircase(i) << '\n';
    // }
    long long res = 1;
    for(int i = 1; i < n; i++){
        int curr = 0;
        while(i<n && !broken[i]){
            i++;
            curr++;
        }
        res*=staircase(curr);
        res%=mod;
        if(broken[i]){
            if(i+1<=n && broken[i+1]) {
                cout <<  "0\n";
                return 0;
            }
        }
    }
    cout << res << '\n';
}