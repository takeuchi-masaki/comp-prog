#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    while(getline(cin, s)){
        int a, b;
        stringstream ss(s);
        ss >> a >> b;
        cout << a << ' ' << b << endl;
    }
}