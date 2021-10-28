/*
ID: themasa1
TASK: sprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> sprime_prev, sprime;

bool checkPrime(int num){
    if(num <= 1) return false;
    if(num <= 3) return true;
    if(num%2 == 0) return false;
    for(int i = 3; i*i <= num; i+=2){
        if(num%i == 0) return false;
    }
    return true;
}

void genNextSprimes(){
    for(int i:sprime_prev){
        int next = i*10;
        for(int j = 1; j <= 9; j+=2){
            if(checkPrime(next+j)){
                sprime.push_back(next+j);
            }
        }
    }
}

int main() {
    freopen("sprime.in","r",stdin); freopen("sprime.out","w",stdout);
    cin >> n;
    sprime_prev = {2, 3, 5, 7};
    sprime = sprime_prev;
    for(int i = 1; i < n; i++){
        sprime.clear();
        genNextSprimes();
        sprime_prev = sprime;
    }
    for(int i:sprime){
        cout << i << '\n';
    }
    return 0;
}