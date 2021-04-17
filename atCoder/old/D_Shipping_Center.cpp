#include <bits/stdc++.h>
using namespace std;
vector<int> w,v,x;
vector<pair<int,int> > wv;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n),v(n),x(m);
    vector<pair<int,int> > wv(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        wv[i] = {w[i],v[i]};
    }
    sort(wv.begin(),wv.end());
    for(int i = 0; i < m; i++){
        cin >> x[i];
    }
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        // cout << l << " " << r << endl;
        vector<int> x2;
        for(int j = 1; j < l; j++){
            x2.push_back(x[j-1]);
        }
        for(int j = r+1; j <= m; j++){
            x2.push_back(x[j-1]);
        }
        sort(x2.begin(),x2.end());
        vector<bool> useWV(n,false);
        int res = 0;
        // cout << x2.size() << endl;
        for(int j = 0; j < x2.size(); j++){
            int currVal = 0, currIndex = -1;
            for(int k = 0; k < n && wv[k].first <= x2[j]; k++){
                if(useWV[k]) continue;
                if(wv[k].second>currVal){
                    currVal = wv[k].second;
                    currIndex = k;
                }
            }
            if(currIndex != -1){
                res+=currVal;
                useWV[currIndex] = true;
            }
        }
        cout << res << endl;
    }
}