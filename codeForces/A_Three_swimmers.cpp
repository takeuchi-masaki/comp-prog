#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b){
    return (a<=b?a:b);
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        long long p, a, b, c;
        cin >> p >> a >> b >> c;
        long long aTime = p%a;
        if(aTime != 0){
            aTime = a-aTime;
        }
        long long bTime = p%b;
        if(bTime != 0){
            bTime = b-bTime;
        }
        long long cTime = p%c;
        if(cTime != 0){
            cTime = c-cTime;
        }
        cout << min(aTime,min(bTime,cTime)) << endl;
    }
}