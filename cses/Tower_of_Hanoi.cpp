#include <bits/stdc++.h>
using namespace std;

void tower(int n, int from, int to, int aux){
    if(n == 1){
        cout << from << ' ' << to << '\n';
        return;
    }
    tower(n-1, from, aux, to);
    cout << from << ' ' << to << '\n';
    tower(n-1, aux, to, from);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cout << (1<<n) - 1 << '\n';
    tower(n, 1, 3, 2);
}