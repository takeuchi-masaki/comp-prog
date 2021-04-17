#include <bits/stdc++.h>
using namespace std;

vector<int> divs(int num){
    vector<int> ret;
    for(int i = 2; i*i <= num; i++){
        if(num%i==0){
            ret.push_back(i);
            if(num/i != i) ret.push_back(num/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i:a)cin>>i;
    int sum = 0, res=n-1;
    {
        // check if all nums are same
        bool allSame = true;
        for(int i:a) if(i!=a[0]) { allSame = false; break; }
        if(allSame){ cout << "0\n"; return; }
    }
    unordered_set<int> prefix;
    for(int i:a){
        sum+=i;
        prefix.insert(sum);
    }
    vector<int> d = divs(sum);
    // check divisors from smallest to greatest
    for(int i:d){
        int num = sum/i;
        bool ok = true;
        for(int j = num; j <= sum; j+=num){
            if(!prefix.count(j)){
                ok = false; break;
            }
        }
        if(ok){
            res = min(res, n-i);
        }
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}