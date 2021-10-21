#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int x, y, n;
    cin >> x >> y >> n;
    for(int i = 1; i <= n; i++){
        string ans = "";
        if(i%x == 0){
            ans.append("Fizz");
        }
        if(i%y == 0){
            ans.append("Buzz");
        }
        if(ans.size()==0) {
            ans = to_string(i);
        }
        cout << ans << endl;
    }
}