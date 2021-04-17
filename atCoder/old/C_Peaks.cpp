#include <iostream>
#include <vector>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    vector<bool> smaller(n), viewed(n), larger(n);
    for(auto& i:h) cin >> i;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << a << endl << b << endl;
        viewed[a] = true;
        viewed[b] = true;
        if(h[a] < h[b]){
            smaller[a] = true;
        }
        if(h[b] < h[a]){
            smaller[b] = true;
        }
        if(h[a] > h[b]){
            larger[a] = true;
        } else if(h[b] > h[a]){
            larger[b] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(viewed[i] && !smaller[i] && larger[i]){
            count++;
        }
    }
    cout << count;
}

