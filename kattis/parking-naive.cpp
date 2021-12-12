#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> cost(4);
    for(int i = 1; i < 4; i++){
        cin >> cost[i];
    }

    const int time_max = 100, cars = 3;
    vector<int> parked(time_max + 1);
    for(int i = 0; i < cars; i++){
        int arrive, depart;
        cin >> arrive >> depart;
        for(int time = arrive; time < depart; time++){
            parked[time]++;
        }
    }

    int sum = 0;
    for(int i : parked){
        sum += i * cost[i];
    }
    cout << sum << '\n';
}