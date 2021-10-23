#include <bits/stdc++.h>
using namespace std;

/*
    koaski

    ko
    as
    ki

    boudonuimilcbsai

    
*/


int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    int count = 1;
    if(n%2 == 0){
        n>>=1;
        while(n>1){
            count++;
            n>>=1;
        }
    }
    cout << count << ' ' << n;
    n = s.size();
}