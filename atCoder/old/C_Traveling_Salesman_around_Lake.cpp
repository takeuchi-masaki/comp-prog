#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int K, N;
    cin >> K >> N;
    vector<int>A(N);
    // perim k
    for(auto& i: A){
        cin >> i;
    }
    int maxDiff = A[0]-A[N-1]+K;
    for(int i = 0; i < N-1; i++){
        int diff = A[i+1]-A[i];
        maxDiff = max(maxDiff,diff);
    }
    cout << K-maxDiff << endl;
}