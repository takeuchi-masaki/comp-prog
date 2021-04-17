#include <bits/stdc++.h>
using namespace std;

void ans(int res){
    cout << res << '\n';
}

// bool check(vector<int>& A) {
//     bool ok = true;
//     for(int i = 0; i < A.size(); i++){
//         if(A[i]==i+1) { return false; }
//     }
//     return true;
// }

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(a[i]==i+1) {
            swap(a[i],a[i+1]);
            res++;
        }
    }
    ans(res);
    // if(check(a)) ans(res);
    // else cout << "WA\n";
}