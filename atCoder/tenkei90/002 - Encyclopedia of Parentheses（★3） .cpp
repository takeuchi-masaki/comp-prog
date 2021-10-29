#include <bits/stdc++.h>
using namespace std;
int n;

bool validateString(string s){
    int count = 0;
    for(char c:s){
        if(c == '('){
            count++;
        } else {
            if(count-- == 0) return false;
        }
    }
    return count == 0;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    if(n&1) return 0;
    vector<string> ans;
    for(int bit = 0; bit < (1<<n); bit++){
        string genString = "";
        int open = 0, close = 0;
        for(int i = 0; i < n; i++){
            if(bit>>i&1) {
                genString.push_back('(');
                open++;
            } else {
                genString.push_back(')');
                close++;
            }
        }
        if(open != close) continue;
        if(validateString(genString)){
            ans.push_back(genString);
        }
    }
    sort(ans.begin(), ans.end());
    for(string s:ans){
        cout << s << '\n';
    }
}