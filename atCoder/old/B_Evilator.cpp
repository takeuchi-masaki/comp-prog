#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long res = s.length()-1;
    for(int i = 1; i < s.length(); i++){
        if(s[i]=='D'){
            res+=i+(s.length()-i-1)*2;
        } else {
            res+=2*i+(s.length()-i-1);
        }
    }
    cout << res << endl;
}