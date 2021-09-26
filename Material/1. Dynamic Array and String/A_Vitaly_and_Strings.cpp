#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    for(int i = s.size()-1; i>=0; i--){
        if(s[i]=='z'){
            s[i]='a';
        } else {
            s[i]++;
            break;
        }
    }
    if(s==t){
        cout << "No such string\n";
    } else {
        cout << s << endl;
    }
}