#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string n; cin >> n;
    // cout << n << ' ' << n.size() << ' ' << n[n.size()-1] << '\n';
    while(n.size()>0 && n[n.size()-1]=='0'){
        n.pop_back();
    }
    // cout << n << '\n';
    if(n.size()==0) {
        cout << "Yes\n";
        return 0;
    }
    string nCopy = n;
    reverse(n.begin(), n.end());
    // cout << n << ' ' << nCopy << '\n';
    if(n==nCopy) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}