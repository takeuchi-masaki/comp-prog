#include <iostream>
using namespace std;

void solve(){
    int num; cin >> num;
    cout << num << " is ";
    if(num&1){
        cout << "odd\n";
    } else {
        cout << "even\n";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout)
    int T = 1;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}