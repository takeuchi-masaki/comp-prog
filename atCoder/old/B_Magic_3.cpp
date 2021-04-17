#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,s,d;
    cin >> n >> s >> d;
    bool dmg = false;
    while(n-- && !dmg){
        int x,y;
        cin >> x >> y;
        if(x < s && y > d) dmg = true;
    }
    cout << (dmg?"Yes":"No");
}

