#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<char> acgt;
    acgt.insert('A');
    acgt.insert('C');
    acgt.insert('G');
    acgt.insert('T');
    string s;
    cin >> s;
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        int curr = 0;
        while(i < s.length() && acgt.count(s[i])){
            ++curr;
            ++i;
        }
        res = max(res,curr);
    }
    cout << res;
}