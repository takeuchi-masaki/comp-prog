#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int count = 0;
    int ans = 1;
    while(ans < b){
        ans+=(a-1);
        ++count;
    }
    cout << count;
}