#include <bits/stdc++.h>
using namespace std;

void recursivePrint(int last, vector<string> & s, vector< vector<int> > & v){
    cout << s[last];
    for(int i : v[last]){
        recursivePrint(i, s, v);
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> s(n+1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    vector< vector<int> > v(n+1);
    int last = 1;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        last = a;
    }
    recursivePrint(last, s, v);
    cout << '\n';
}