#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long res = 0, mult = 1000;
    while(n>=mult){
        res+=n-mult+1;
        mult*=1000;
    }
    cout << res << endl;

//     long long copy = n;
//     int digit = -1;
//     while(copy>0){
//         copy/=1000;
//         digit++;
//     }
//     // cout << digit << endl;
//     long long subtr = 1;
//     for(int i = 0; i < digit; i++){
//         subtr*=1000;
//     }
//     // cout << subtr << endl;
//     long long comm = (n-subtr+1)*digit;
//     long long prev = subtr;
//     digit--;
//     while(digit>0){
//         subtr/=1000;
//         comm+=(prev-subtr)*digit;
//         prev = subtr;
//         digit--;
//     }
//     cout << comm << endl;
}