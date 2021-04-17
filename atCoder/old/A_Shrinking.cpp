#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 1e9;
    for(char c = 'a'; c <= 'z'; c++){
        string t = s;
        for(int i = 0; ; i++){
            if(t.empty()) break;
            if(t == string(t.length(),c)){
                res = min(res,i);
                break;
            }
            string next = "";
            for(int j = 0; j < (int)t.size()-1; j++){
                if(t[j]==c || t[j+1]==c){
                    next+=c;
                } else {
                    next+=t[j];
                }
            }
            t = next;
        }
        
    }
    cout << res << endl;
}