#include <bits/stdc++.h>
using namespace std;

const long double a2short = powl(2, (double)-5/4),
a2long = powl(2, (double)-3/4),
a_ratio = sqrtl(2);
int n;
long double ans = 0;
vector<int> paper_count;
vector<long double> aLong, aShort;

void tape(int aSize, int need){
    if(aSize == n+1){
        return;
    }
    if(paper_count[aSize] >= need){
        paper_count[aSize-1] += need/2;
        paper_count[aSize] -= need;
        ans += aLong[aSize]*need/2;
    } else {
        int diff = need-paper_count[aSize];
        tape(aSize+1, diff*2);
        if(paper_count[aSize] < need) return;
        paper_count[aSize-1] += need/2;
        paper_count[aSize] -= need;
        ans += aLong[aSize]*need/2;
    }
}

int main(){
    // freopen("input.txt","r",stdin); freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    paper_count = vector<int>(n+1);
    for(int i = 2; i <= n; i++){
        cin >> paper_count[i];
    }
    aLong = aShort = vector<long double>(n+1);
    aLong[2] = a2long;
    aShort[2] = a2short;
    for(int i = 3; i <= n; i++){
        aShort[i] = aLong[i-1]/2;
        aLong[i] = aShort[i] * a_ratio;
    }
    // oops, there's a simplification
    // for(int i = 2; i <= n; i++){
    //     cout << aLong[i] << ' ' << aShort[i] << '\n';
    // }
    
    tape(2, 2);
    if(paper_count[1] != 1) {
        cout << "impossible\n";
        return 0;
    }
    cout << fixed << setprecision(11);
    cout << ans << endl;
}