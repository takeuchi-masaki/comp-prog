#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(auto& i:h) cin >> i;
    int res = 0;
    for(int i = 1; i < n; i++){
        int currH = h[i-1],curr=0;
        while(i < n && h[i-1]>=h[i]){
            i++;
            curr++;
        }
        res = max(res,curr);
    }
    cout << res << endl;
}