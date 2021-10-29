#include <bits/stdc++.h>
using namespace std;

int digitSum(int num){
    int ans = 0;
    while(num){
        ans += num%10;
        num/=10;
    }
    return ans;
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, a, b; cin >> n >> a >> b;
    long long ans = 0;
    for(int i = 1; i<=n; i++){
        int digSum = digitSum(i);
        if(digSum >= a && digSum <= b){
            ans+=i;
        }
    }
    cout << ans << endl;
}