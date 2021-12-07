#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // cakes, types of cakes
    int k, t; cin >> k >> t;
    vector<int> cake_count(t);
    for(int & i : cake_count) cin >> i;

    int sum_all = accumulate(cake_count.begin(), cake_count.end(), 0);
    int max_cake = *max_element(cake_count.begin(), cake_count.end());
    max_cake <<= 1;
    if(max_cake <= sum_all){
        cout << "0\n";
        return 0;
    }
    cout << max_cake - sum_all - 1 << '\n';
}