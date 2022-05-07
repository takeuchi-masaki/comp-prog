#include <bits/stdc++.h>

using namespace std;

int main (){
    long long int N, M;
    cin >> N >> M;
    long long int ar[N];
    for(int i = 0; i < N; i++)cin >> ar[i];
    sort(ar,ar+N);
    long long int ans;
    int i = N-1;
    int m = 1;

    while(i>=0){
        long long int hd = (i==0)?ar[i] : ar[i] - ar[i-1];
        if(M - (hd) * m <= 0){
            ans = ar[i] - (M + m - 1)/m;
            break;
        }
        M -= (hd) * m;
        i--;
        m++;
    }
    cout << ans;
}