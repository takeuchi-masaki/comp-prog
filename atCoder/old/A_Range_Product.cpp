#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string res;
    if(a < 0 && b < 0){
        if((a-b-1)&1){
            res = "Negative";
        } else {
            res = "Positive";
        }
    } else if(a < 0 && b >= 0){
        res = "Zero";
    } else {
        res = "Positive";
    }
    cout << res << endl;
}