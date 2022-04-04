#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> scores(n), copy;
    for(int & i : scores){
        for(int day = 0; day < 3; day++){
            int score; cin >> score;
            i += score;
        }
    }
    copy = scores;
    sort(copy.rbegin(), copy.rend());
    int target = copy[k - 1];
    for(int i : scores){
        cout << ((i + 300 >= target) ? "Yes\n" : "No\n");
    }
}