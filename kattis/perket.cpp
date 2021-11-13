#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N; // number of ingredients
    vector<int> sourness(N), bitterness(N);
    for(int i = 0; i < N; i++){
        cin >> sourness[i] >> bitterness[i];
    }
    
    int ans = 1e9+7;
    
    for(int num = 0; num < pow(3, N); num++){
        int div = 1;
        vector<int> group(N);
        for(int bit = 0; bit < N; bit++){
            group[bit] = num / div % 3;
            div *= 3;
        }
        /* 
            do stuff with the 3 groups here
        */
        
    }

}