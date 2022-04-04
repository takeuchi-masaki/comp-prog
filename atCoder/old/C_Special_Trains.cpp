#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> time_to_next(n - 1), first_train(n - 1), period_time(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> time_to_next[i] >> first_train[i] >> period_time[i];
    }

    vector<int> ans(n);
    for(int start_station = 0; start_station < n - 1; start_station++){
        int curr = first_train[start_station] + time_to_next[start_station];
        for(int station = start_station + 1; station < n - 1; station++){
            if(curr <= first_train[station]){
                curr = first_train[station] + time_to_next[station];
            } else {
                int diff = curr - first_train[station];
                int next_available_train = 
                    (diff + period_time[station] - 1) / period_time[station];
                curr = first_train[station] 
                    + next_available_train * period_time[station] 
                    + time_to_next[station];
            }
        }
        cout << curr << '\n';
    }
    cout << "0\n";
}