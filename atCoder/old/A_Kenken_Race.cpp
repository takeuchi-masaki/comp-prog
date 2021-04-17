#include <bits/stdc++.h>
using namespace std;

void ans(bool ok){
    cout << (ok?"Yes\n":"No\n");
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b, c, d; string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--; // 0 index

    int far = max(c,d);
    for(int i = a+1; i<far-1; i++){
        if(s[i]=='#' && s[i+1]=='#'){
            ans(false);
            return 0;
        }
    }

    if(c>d){
        bool ok = false;
        while(b<d){
            if(s[b-1]!='#' && s[b+1]!='#') {
                ans(true);
                return 0;
            }
            if(s[b+1]=='#') b+=2;
            else b++;
        }
        if(s[b-1]!='#' && s[b+1]!='#') ok = true;
        ans(ok);
        return 0;
    }
    ans(true);
    return 0;
}