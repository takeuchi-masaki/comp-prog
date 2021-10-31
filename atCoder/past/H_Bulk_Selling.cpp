#include <bits/stdc++.h>
using namespace std;

int n, q;
long long totalSales = 0;
vector<int> stock;
const int INF = 1e9+7;
int minOdd = INF, minTotal = INF;
int subtractAll = 0, subtractOdd = 0;

void sell(int card, int quantity){
    totalSales += quantity;
    stock[card] -= quantity;
    if(card%2 == 0){
        minOdd = min(minOdd, stock[card]);
    }
    minTotal = min(minTotal, min(minOdd-subtractOdd, stock[card]));
}

int currStock(int card){
    if(card%2 == 0){
        return stock[card]-subtractAll-subtractOdd;
    } else {
        return stock[card]-subtractAll;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    stock = vector<int>(n);
    for(int & i:stock) cin >> i;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            minOdd = min(minOdd, stock[i]);
        }
        minTotal = min(minTotal, stock[i]);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int command; cin >> command;
        if(command == 1){
            int x, a; cin >> x >> a;
            x--;
            if(currStock(x) < a) continue;
            sell(x, a);
        } else if(command == 2){
            int a; cin >> a;
            if(minOdd-subtractAll-subtractOdd < a){
                continue;
            }
            subtractOdd += a;
            totalSales += (long long)a*((n+1)/2);
        } else if(command == 3){
            int a; cin >> a;
            if(
                min(minTotal,
                    minOdd-subtractOdd)-subtractAll < a
            ) continue;
            subtractAll += a;
            totalSales += (long long)a*n;
        }
    }
    cout << totalSales << '\n';
}