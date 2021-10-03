#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int maxRep = 1;
    for(int i = 0; i < s.size()-1; i++){
        int currRep = 1;
        while(i < s.size()-1 && s[i] == s[i+1]){
            i++;
            currRep++;
        }
        maxRep = max(maxRep, currRep);
    }
    cout << maxRep << endl;
}