#include <iostream>
using namespace std;

long long frq[100001];

int main(){
    long long n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        frq[a]+=b;
    }
    long long cnt = 0;
    for(int i = 1; i <= 100000; i++){
        cnt+=frq[i];
        if(cnt >= (long long)k){
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}