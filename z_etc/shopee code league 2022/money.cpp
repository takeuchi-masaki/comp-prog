#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); i++)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<string, ll> psi;
typedef vector<int> vi; 
typedef vector<ll>  vl;


int main (){
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    map<string,ll> mp;
    string name;
    ll money;
    int N, T;
    cin >> N >> T;
    rep(i, 0, N){
        cin >> name >> money;
        mp.insert({name, money});
    }
    string a, b;
    ll amt;
    rep(i, 0, T){
        cin >> a >> b >> amt;
        if(mp[a] > amt){
            mp[a] -= amt;
            mp[b] += amt; 
        }

    }
    for(map<string, ll>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        cout << itr->first << " ";
        cout << itr->second << endl;
    }
}
