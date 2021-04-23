#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int even[MAX+1], odd[MAX+1];

int main(){
    // freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for(int& i:v)cin>>i;
    for(int i = 0; i < n; i+=2){
        even[v[i]]++;
    }
    for(int i = 1; i < n; i+=2){
        odd[v[i]]++;
    }
    int maxEvenCnt[2] = {}, maxOddCnt[2] = {};
    int maxEven, maxOdd;
    for(int i = 0; i <= MAX; i++){
        if(even[i]>maxEvenCnt[1]){
            if(even[i]>maxEvenCnt[0]){
                maxEvenCnt[1]=maxEvenCnt[0];
                maxEvenCnt[0]=even[i];
                maxEven = i;
            } else {
                maxEvenCnt[1]=even[i];
            }
        }
        if(odd[i]>maxOddCnt[1]){
            if(odd[i]>maxOddCnt[0]){
                maxOddCnt[1]=maxOddCnt[0];
                maxOddCnt[0]=odd[i];
                maxOdd = i;
            } else {
                maxOddCnt[1]=odd[i];
            }
        }
    }
    long long res = n;
    if(maxEven == maxOdd){
        res -= max(maxEvenCnt[0]+maxOddCnt[1], maxEvenCnt[1]+maxOddCnt[0]);
    } else {
        res -= maxEvenCnt[0] + maxOddCnt[0];
    }
    cout << res << '\n';
}