#include <bits/stdc++.h>
using namespace std;

struct card{
    int w, h, q;
    card(int wid, int hei, int qua){
        w = wid, h = hei, q = qua;
    }
};

int main(){
    int n, k; cin >> n >> k;
    if(n==k) {
        cout << "0\n";
        return 0;
    }
    int wMax = 0, hMax = 0;
    vector<card> cards(n);
    for(int i = 0; i < n; i++){
        int w, h, q; cin >> w >> h >> q;
        cards[i] = card(w, h, q);
        wMax = max(wMax, w);
        hMax = max(hMax, h);
    }
    
}