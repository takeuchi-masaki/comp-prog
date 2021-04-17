#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, h;
    cin >> m >> h;
    if(h%m==0){
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
}