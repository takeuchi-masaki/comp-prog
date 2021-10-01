#include <iostream>
using namespace std;

void solve(){
    int r, e, c;
    cin >> r >> e >> c;
    if(e - r == c){
        cout << "does not matter\n";
    } else if(e-r > c){
        cout << "advertise\n";
    } else {
        cout << "do not advertise\n";
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