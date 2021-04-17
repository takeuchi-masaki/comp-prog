#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    vector< pair<int,int> > ab(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i]; 
        ab[i] = {b[i],a[i]};
    }
    sort(ab.begin(),ab.end());
    long long currTime = 0;
    bool ok = true;
    for(auto [x,y]:ab){
        currTime+=y;
        if(currTime>x) {
            ok = false;
            break;
        }
    }
    cout << (ok?"Yes":"No") << endl;
}