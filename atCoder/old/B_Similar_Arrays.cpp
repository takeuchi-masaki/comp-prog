#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& i:a) cin >> i;
    // check for number 1 larger, 1 smaller, same vai
    // 1 of the digits must be even
    int evenCount = 0;
    for(int i:a) if((i&1)==0) evenCount++;
    long long res = 1;
    for(int i = 0; i < n; i++){
        res*=3;
    }
    res-=1LL<<evenCount;
    cout << res << endl;
}