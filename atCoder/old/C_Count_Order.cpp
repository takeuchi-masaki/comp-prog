#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n), q(n), perm(n);
    for(auto& i: p) cin >> i;
    for(auto& i: q) cin >> i;
    iota(perm.begin(), perm.end(), 1);
    int count = 0;
    int a, b;
    do{
        count++;
        if(perm == p){
            a = count;
        }
        if(perm == q){
            b = count;
        }
    } while(next_permutation(perm.begin(), perm.end()));
    cout << abs(a - b);
}