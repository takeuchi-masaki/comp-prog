#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int middle = 2; // index (2, 2)
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int num; cin >> num;
            if(num){
                // manhattan distance
                cout << abs(i - middle) + abs(j - middle) << '\n';
                return 0;
            }
        }
    }
}