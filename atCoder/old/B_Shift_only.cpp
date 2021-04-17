#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 1E9;
    while(n--){
        int temp;
        cin >> temp;
        if(temp&1) {
            res = 0;
            break;
        }
        int curr = 0;
        while( (temp&1)==0 && temp>=2 ){
            temp>>=1;
            curr++;
        }
        res = min(res,curr);
    }
    cout << res << endl;
}