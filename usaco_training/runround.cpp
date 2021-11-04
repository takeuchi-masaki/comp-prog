/*
ID: themasa1
TASK: runround
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

bool not_unique(string ll){
    vector<bool> digit(10);
    for(int i = 0; i < ll.size(); i++){
        if(digit[ll[i]-'0']) return true;
        digit[ll[i]-'0'] = true;
    }
    return false;
}

int main() {
    freopen("runround.in","r",stdin); freopen("runround.out","w",stdout);
    long long m; cin >> m;
    while(m++){
        string ll = to_string(m);
        int n = ll.size();
        if( not_unique(ll) ) continue;
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            set<char> left;
            for(char c:ll) left.insert(c);
            int currIndex = i;
            while(!left.empty()){
                if( !left.count(ll[currIndex]) ) break;
                left.erase( ll[currIndex] );
                currIndex = (currIndex + ll[currIndex] - '0') % n;
            }
            if(!left.empty()) ok = false;
        }
        if(ok){
            cout << ll << '\n';
            return 0;
        }
    }
    return 0;
}