#include <bits/stdc++.h>
using namespace std;

int mx = 50;


int main(){
    srand(time(nullptr));
    freopen("small1.txt","w",stdout);
    int n = 3, k = rand()%mx;
    vector<int> a(1<<n);
    unordered_set<int> used;
    for(int i = 0; i < (1<<n); i++){
        int rnd = rand()%mx;
        while(!used.insert(rnd).second) {
            rnd = rand()%mx;
        }
        a[i] = rnd;
    }
    cout << n << ' ' << k << '\n';
    sort(a.rbegin(), a.rend());
    for(int i : a) cout << i << '\n';
}