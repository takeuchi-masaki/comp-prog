/*
ID: themasa1
TASK: zerosum
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("zerosum.in","r",stdin); freopen("zerosum.out","w",stdout);
    int n; cin >> n;
    vector<string> ans;
    for(int mask = 0; mask < pow(3, n-1); mask++){
        vector<int> op(n-1);
        int mult = 1;
        for(int bit = 0; bit < n-1; bit++){
            op[bit] = (mask/mult)%3;
            mult *= 3;
        }
        int sum = 0, prev = 1, nextop = 1;
        for(int i = 0; i < n-1; i++){
            if(op[i] == 0){
                prev *= 10;
                prev += i+2;
                continue;
            }
            if(nextop == 1){
                sum += prev;
            } else {
                sum -= prev;
            }
            prev = i+2;
            if(op[i] == 1){
                nextop = 1;
            } else {
                nextop = -1;
            }
        }
        if(nextop == 1){
            sum += prev;
        } else {
            sum -= prev;
        }
        
        if(sum == 0){
            string sol = "1";
            for(int i = 0; i < n-1; i++){
                switch(op[i]){
                    case 0: sol.push_back(' '); break;
                    case 1: sol.push_back('+'); break;
                    case 2: sol.push_back('-'); break;
                }
                sol.push_back((i+2+'0'));
            }
            ans.push_back(sol);
        }
    }
    sort(ans.begin(), ans.end());
    for(string s:ans) cout << s << '\n';
    return 0;
}