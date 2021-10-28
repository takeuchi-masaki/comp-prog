/*
ID: themasa1
TASK: ariprog
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool bs[2*250*250 +1];

bool check(int st, int diff){
    for(int i = 1; i < n; i++){
        if(!bs[st + diff*i]) return false;
    }
    return true;
}

int main() {
    freopen("ariprog.in","r",stdin); freopen("ariprog.out","w",stdout);
    cin >> n >> m; // len, bisquare limit
    for(int p = 0; p <= m; p++){
        for(int q = 0; q <= m; q++){
            bs[p*p + q*q] = 1;
        }
    }
    
    vector< pair<int,int> > ans;
    for(int start = 0; start < (2*m*m); start++){
        if(!bs[start]) continue;
        for(int diff = 1; diff <= (2*m*m-start)/(n-1); diff++){
            if(check(start, diff)){
                ans.push_back(make_pair(diff, start));
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(pair<int,int> p:ans){
        cout << p.second << ' ' << p.first << '\n';
    }
    if(ans.empty()){
        cout << "NONE\n";
    }
    return 0;
}