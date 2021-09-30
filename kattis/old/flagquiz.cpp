#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; getline(cin, s); // ignore first line
    int n; cin >> n;
    n--;
    getline(cin, s);
    int prev = 0, partitions = 0;
    vector< map<string, int> > vec;
    for(int i = 0; i <= s.size(); i++){
        if(i==s.size() || s[i]==','){
            partitions++;
            string add = s.substr(prev, );

        }
    }
    for(int i = 1; i < n; i++){
        string s;
        getline(cin, s);
        // cout << s << endl;
    }
}