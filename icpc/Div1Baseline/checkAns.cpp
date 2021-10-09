#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    bool ok = true;

    freopen("wormhole.out", "r", stdin);
    vector<string> s1;
    string s;
    while( cin >> s ){
        s1.push_back(s);
    }
    freopen("out.txt", "r", stdin);
    int i = 0;
    while( cin >> s ){
        if(s != s1[i]){
            cout << "NG line " << i << endl;
            ok = false;
        }
        i++;
    }
    if(ok){
        cout << "ALL CLEAR\n";
    }
}