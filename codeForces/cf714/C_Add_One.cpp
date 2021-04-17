#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

map< pair<int,int>, int > mp;
 
int calc(string num, int m){
    int n = stoi(num);
    pair<int,int> p = make_pair(n,m);
    if( mp.count(p) ){
        return mp[p];
    }

    if(m<(10-n)) {
        mp[p] = 1;
    } else {
        int next = m-(10-n);
        mp[p] = (calc("1", next) + calc("0", next))%mod;
    }
    return mp[p];
    // if(num.size()==1){
        
    // }
    
    // int res = 0;
    // for(int i = 0; i < num.size(); i++){
    //     int curr = num[i]-'0';
    //     int next = 10-curr;
    //     if(m < next) {
    //         res++;
    //         continue;
    //     }
    //     res+=calc( num.substr(i,1), m-next );
    //     res%=mod;
    // }
    // mp.insert(make_pair(p, res));
    // return mp[p];
}

void solve(){
    string n;
    int m; cin >> n >> m;
    int res = 0;
    for(int i = 0; i < n.size(); i++){
        res+=calc(n.substr(i,1), m);
        res%=mod;
    }
    cout << res << '\n';
    // int start_size = n.size();
    // long long res = start_size;
    // for(int i = 0; i < start_size; i++){
    //     int curr = n[i]-'0';
    //     int mCopy = m;
    //     int first = 10-curr;
    //     mCopy-=first;
    //     if(mCopy<0) continue;
    //     res++;
    //     mCopy-=10;
    //     if(mCopy<0) continue;
    //     res+=mCopy;
    //     res%=mod;
    //     while(mCopy>0){
    //         res+=mCopy;
    //         res%=mod;
    //         // if(res>=mod) res-=mod;
    //         mCopy-=10;
    //     }
    // }
    // cout << res << '\n';
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