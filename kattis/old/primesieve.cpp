#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    // bool prime[n+1];
    // memset(prime, true, sizeof(prime));
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i){
                prime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2; i<=n; i++){
        if(prime[i]) count++;
    }
    cout << count << '\n';
    for(int i = 0; i < q; i++){
        int num; cin >> num;
        cout << prime[num] << '\n';
    }
}