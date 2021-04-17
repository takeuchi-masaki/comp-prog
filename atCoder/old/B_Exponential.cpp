#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    int res = 1;
    for(int i = 2; i*i <= x; i++){
        int curr = i*i;
        for(int j = 0; curr <= x; j++){
            res = max(curr,res);
            curr*=i;
        }
    }
    cout << res << endl;
}