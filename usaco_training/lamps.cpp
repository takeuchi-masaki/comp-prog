/*
ID: themasa1
TASK: lamps
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<string> toggles;
set<string> sol;

string xorstring(string curr, string toggle){
    string ans = "";
    for(int i = 0; i < n; i++){
        if( (curr[i] - '0') - (toggle[i] - '0') ){
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }
    return ans;
}

void dfs(string curr, int count){
    if(count == c){
        sol.emplace(curr);
        return;
    }
    for(int i = 0; i < 4; i++){
        dfs(xorstring(curr, toggles[i]), count+1);
    }
}

int main() {
    freopen("lamps.in","r",stdin); freopen("lamps.out","w",stdout);
    cin >> n >> c;
    c = min(c, 4);
    vector<int> final(n);
    int lamp;
    while(true){
        cin >> lamp;
        if(lamp == -1) break;
        final[lamp-1] = 1;
    }
    while(true){
        cin >> lamp;
        if(lamp == -1) break;
        final[lamp-1] = -1;
    }
    string toggleAll = "", toggleEven = "", toggleOdd = "", toggle3 = "";
    for(int i = 1; i <= n; i++){
        toggleAll.push_back('1');
        if(i&1){
            toggleEven.push_back('0');
            toggleOdd.push_back('1');
        } else {
            toggleEven.push_back('1');
            toggleOdd.push_back('0');
        }
        if((i-1)%3 == 0){
            toggle3.push_back('1');
        } else {
            toggle3.push_back('0');
        }
    }
    toggles = {
        toggleAll,
        toggleEven,
        toggleOdd,
        toggle3
    };
    dfs(toggleAll, 0);

    bool notFound = true;
    for(string s:sol){
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            if(final[i] == 0) continue;
            if(final[i] == 1){
                if(s[i] == '0') ok = false;
            } else {
                if(s[i] == '1') ok = false;
            }
        }
        if(ok) {
            cout << s << '\n';
            notFound = false;
        }
    }
    if(notFound){
        cout << "IMPOSSIBLE\n";
        return 0;
    }    
    return 0;
}