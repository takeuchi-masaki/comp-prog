#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    if(n < m){
        if(m - n == 1){
            printf("Dr. Chaz will have %d piece of chicken left over!",(m-n));
        } else {
            printf("Dr. Chaz will have %d pieces of chicken left over!",(m-n));
        }
    } else if(n > m) {
        if(n - m == 1){
            printf("Dr. Chaz needs %d more piece of chicken!",(n-m));
        } else {
            printf("Dr. Chaz needs %d more pieces of chicken!",(n-m));
        }
    }
}

