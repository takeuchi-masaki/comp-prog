#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    int peak_max = (n-1)/2;
    if(k>peak_max) {
        cout << "-1\n";
        return;
    }
    vector<int> a(n);
    // for(int i = 0; i < n; i++){
    //     a[i] = i+1;
    // }
    int smallest = 1, largest = n, index = 0;
    int peakCnt = 0;
    a[index++] = smallest++;
    while(peakCnt!=k){
        a[index++] = largest--;
        a[index++] = smallest++;
        peakCnt++;
    }
    while(smallest<=largest){
        a[index++] = smallest++;
    }
    for(int i:a){
        cout << i << ' ';
    }
    cout << '\n';
    // cout << 1 << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}