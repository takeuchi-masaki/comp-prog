#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+1),b(n+1), tm(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> tm[i];
        }
        int currTime = 0;
        for(int i = 1; i < n; i++){
            currTime += a[i]-b[i-1]+tm[i]+ (int)ceil( (b[i]-a[i])/2.0 );
            currTime = max(currTime,b[i]);
        }
        currTime += a[n]-b[n-1]+tm[n];
        cout << currTime << endl;
    }
}