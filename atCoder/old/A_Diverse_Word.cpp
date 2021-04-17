#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    int n = s.size();

    if(n<26){
        bool letter[26]={};
        for(int i = 0; i < n; i++){
            letter[s[i]-'a']=true;
        }
        for(int i = 0; i < 26; i++){
            if(!letter[i]){
                cout << s << (char)(i+'a') << '\n';
                return 0;
            }
        }
        // string copy = s;
        // sort(s.begin(),s.end());
        // for(char c = 'a'; c<='z'; c++){
        //     if(s[c-'a']!=c){
        //         cout << copy << c << '\n';
        //         return 0;
        //     }
        // }
        // return 0; implicit
    }

    set<char> seen;
    for(int i = n-1; i>0; i--){
        seen.insert(s[i]);
        auto it = seen.upper_bound(s[i-1]);
        if(it == seen.end()) continue;
        char end = *it;
        s[i-1]=end;
        string res = "";
        for(int j = 0; j < i; j++){
            res.push_back(s[j]);
        }
        cout << res << '\n';
        return 0;
    }
    cout << "-1\n";
    return 0;
}