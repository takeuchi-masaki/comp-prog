#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int res = 0;
    set<int> s;
    for(int i = 1; i<=n; i++){
        res+=i;
        s.insert(i);
        if(res>=n){
            if(res==n) break;
            s.erase(res-n);
            break;
        }
    }
    for(int i:s){
        cout << i << '\n';
    }
}