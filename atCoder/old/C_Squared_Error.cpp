#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), count(401);
    for(auto& i:a) cin >> i;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        count[a[i]+200]++;
    }
    for(int i = 0; i < 400; i++){
        if(count[i]>0){
            for(int j = i+1; j<401; j++){
                if(count[j]>0){
                    int num1 = i-200;
                    int num2 = j-200;
                    int diff = num1 - num2;
                    sum += ((long long)diff*diff) * count[i] * count[j];
                }
            }
        }
    }
    cout << sum << endl;
}