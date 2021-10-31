#include <bits/stdc++.h>
using namespace std;

struct custom_compare{
    bool operator() (string s1, string s2){
        s1[0] += 32;
        s1[s1.size()-1] += 32;
        s2[0] += 32;
        s2[s2.size()-1] += 32;
        // cout << s1[0] << ' ' << s1[s1.size()-1] << '\n';
        // cout << s2[0] << ' ' << s2[s2.size()-1] << '\n';
        for(int i = 0; i < min(s1.size(), s2.size()); i++){
            if(s1[i] == s2[i]) continue;
            if(s1[i] < s2[i]){
                return true;
            } else {
                return false;
            }
        }
        return s1.size() < s2.size();
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    vector<string> words;
    int idx = 0;
    while(idx < s.size()){
        string curr = "";
        curr.push_back( s[idx++] );
        while(idx < s.size() && s[idx] > 'Z'){
            curr.push_back(s[idx++]);
        }
        curr.push_back( s[idx++] );
        words.push_back(curr);
    }
    sort(words.begin(), words.end(), custom_compare());
    // for(int i = 0; i < words.size(); i++){
    //     cout << words[i] << endl;
    // }
    for(string word:words){
        cout << word;
    }
}