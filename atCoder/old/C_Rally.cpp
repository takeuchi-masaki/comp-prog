#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    int min = INT_MAX;
    for(int i = 1; i <= 100; i++){
        int stamina = 0;
        for(int j = 0; j < n; j++){
            int diff = x[j]-i;
            stamina+= diff * diff;
        }
        if(min > stamina) min = stamina;
    }
    cout << min;
}

