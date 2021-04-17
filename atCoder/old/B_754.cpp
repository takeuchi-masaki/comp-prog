#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string num = s.substr(0,3);
    int i = 3;
    int res = abs(stoi(num)-753);
    while(i<s.length()){
        num=num.substr(1);
        num+=s[i];
        i++;
        res = min(abs(stoi(num)-753),res);
    }
    cout << res << endl;
}