#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int ticket_count, customer_count; cin >> ticket_count >> customer_count;
    map<int,int> m;
    for(int i = 0; i < ticket_count; i++){
        int price; cin >> price;
        m[price]++;
    }
    for(int i = 0; i < customer_count; i++){
        int max_price; cin >> max_price;
        auto it = m.lower_bound(max_price);
        if(it == m.begin() && it->first != max_price){
            cout << "-1\n";
            continue;
        }
        if(it == m.end() || it->first != max_price) it--;
        cout << it->first << '\n';
        if(--m[it->first] == 0){
            m.erase(it->first);
        }
    }
}