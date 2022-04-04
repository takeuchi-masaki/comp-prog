#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    sort(s.begin(), s.end());
    bool odd = (s.size()&1);
    int ans = 0;
    do{
        string n1, n2;
        if(odd){
            n1 = s.substr(0, s.size()/2);
            n2 = s.substr(s.size()/2, s.size()/2+1);
            ans = max(ans, stoi(n1)*stoi(n2));

            n1 = s.substr(0, s.size()/2+1);
            n2 = s.substr(s.size()/2+1, s.size()/2);
            ans = max(ans, stoi(n1)*stoi(n2));
        } else {
            n1 = s.substr(0, s.size()/2);
            n2 = s.substr(s.size()/2, s.size()/2);
            ans = max(ans, stoi(n1)*stoi(n2));
        }
    } while(next_permutation(s.begin(), s.end()));
    cout << ans << endl;
}