#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, w;
    cin >> a >> b >> w;
    w*=1000;
    int upper = w/a;
    int lower = ceil((double)w/b);
    if(lower<=upper){
        cout << lower << " " << upper << endl;
    } else {
        cout << "UNSATISFIABLE" << endl;
    }
}