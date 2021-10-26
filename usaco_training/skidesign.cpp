/*
ID: themasa1
TASK: skidesign
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;



int main() {
    freopen("skidesign.in","r",stdin); freopen("skidesign.out","w",stdout);
    int n; cin >> n;
    vector<int> h(n);
    for(int&i:h) cin >> i;
    int ans = 1e9;
    for(int minH = 0; minH+17 <= 100; minH++){
        int maxH = minH + 17;
        int currCost = 0;
        for(int i:h){
            if(i < minH){
                currCost += (minH-i)*(minH-i);
            } else if(i > maxH){
                currCost += (i-maxH)*(i-maxH);
            }
        }
        ans = min(ans, currCost);
    }
    cout << ans << endl;
    
    return 0;
}