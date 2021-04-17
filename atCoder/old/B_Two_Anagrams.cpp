#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int a[26] = {},b[26] = {};
    for(int i = 0; i < s.length(); i++){
        char c = s[i];
        int letter = (int)c-(int)'a';
        a[letter]++;
        // cout << a[letter] << endl;
    }
    for(int i = 0; i < t.length(); i++){
        char c = t[i];
        int letter = (int)c-(int)'a';
        b[letter]++;
        // cout << b[letter] << endl;
    }
    string res1 = "", res2 = "";
    for(int i = 0; i < 26; i++){
        int count1 = a[i];
        int count2 = b[i];
        while(count1--){
            res1+=(char)(i+(int)'a');
        }
        while(count2--){
            res2 = (char)(i+(int)'a') + res2;
        }
    }
    // cout << res1 << " " << res2 << endl;
    cout << (res1<res2?"Yes":"No");
}