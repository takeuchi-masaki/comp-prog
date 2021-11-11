#include <bits/stdc++.h>
using namespace std;
int cities, boxes;

bool isOk(int mid, vector<int> & pop){
    int boxCount = 0;
    for(int i : pop){
        boxCount += (i + mid - 1) / mid;
        if(boxCount > boxes) return false;
    }
    return true;
}

int bin(int pop_max, vector<int> & pop){
    int ok = pop_max, bad = 0;
    while(abs(ok-bad) > 1){
        int mid = (ok + bad) / 2;
        if(isOk(mid, pop)) ok = mid;
        else bad = mid;
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    while(true){
        cin >> cities >> boxes;
        if(cities == -1 && boxes == -1) break;
        int pop_max = 0;
        vector<int> pop(cities);
        for(int i = 0; i < cities; i++){
            cin >> pop[i];
            pop_max = max(pop_max, pop[i]);
        }
        cout << bin(pop_max, pop) << '\n';
    }
}