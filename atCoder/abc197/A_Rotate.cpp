#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    s.push_back(s[0]);
    s = s.substr(1);
    cout << s << endl;
}