#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, count = 1;
    while(true){
        cin >> n;
        if(n == 0) break;
        cout << "SET " << count++ << endl;
        vector<string> a, b;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            if(i&1) {
                b.push_back(s);
            } else {
                a.push_back(s);
            }
        }
        reverse(b.begin(), b.end());
        for(string ss:a){
            cout << ss << endl;
        }
        for(string ss:b){
            cout << ss << endl;
        }
    }
}