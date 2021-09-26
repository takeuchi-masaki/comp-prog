#include <iostream>
#include <vector>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a){
        cin >> i;
    }
    // alice left to right, bob right to left
    vector<int> left(n), right(n);
    left[0] = a[0], right[0] = a[n-1];
    for(int i = 1; i < n; i++){
        left[i] = left[i-1] + a[i];
        right[i] = right[i-1] + a[n-i-1];
    }
    // for(int i = 0; i < n; i++){
    //     cout << left[i] << ' ';
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << right[i] << ' ';
    // }
    // cout << endl;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        if(left[ans1]<=right[ans2]){
            ans1++;
        } else {
            ans2++;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}