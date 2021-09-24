#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    bool needTree = false, needAutomaton = false, needArray = true;
    vector<int> ss(26), tt(26);
    for(int i = 0; i < s.length(); i++){
        ss[s[i]-'a']++;
    }
    for(int i = 0; i < t.length(); i++){
        tt[t[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        // cout << tt[i] << " " << ss[i] << endl;
        if(tt[i]>ss[i]){
            needTree = true;
            break;
        }
        if(ss[i]>tt[i]){
            needAutomaton = true;
        }
    }
    if(needTree){
        cout << "need tree" << endl;
    } else {
        int curr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[curr]){
                curr++;
                if(curr == t.size()) {
                    needArray = false;
                    break;
                }
            }
        }
        if(needAutomaton && needArray){
            cout << "both" << endl;
        } else if(needArray){
            cout << "array" << endl;
        } else if(needAutomaton){
            cout << "automaton" << endl;
        }
    }
}