#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B), x(M),y(M),c(M);
    int minA = INT_MAX, minB = INT_MAX;
    for(int i = 0; i < A; i++){
        cin >> a[i];
        minA = min(minA, a[i]);
    }
    for(int i = 0; i < B; i++){
        cin >> b[i];
        minB = min(minB, b[i]);
    }
    for(int i = 0; i < M; i++){
        cin >> x[i] >> y[i] >> c[i];
    }
    int res = INT_MAX;
    for(int i = 0; i < M; i++){
        int curr = a[x[i]-1] + b[y[i]-1] - c[i];
        res = min(res,curr);
    }
    cout << min(res,minA+minB) << endl;
}