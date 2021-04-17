#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int mod = 1000000007;
struct mint {
  unsigned int x;
  mint(): x(0) {}
  mint(long long x):x((x%mod+mod)%mod) {}
  mint operator-() const { return mint(0) - *this; }
  mint operator~() const { return mint(1) / *this; }
  mint& operator+=(const mint& a) { if((x+=a.x)>=mod) x-=mod; return *this; }
  mint& operator-=(const mint& a) { if((x+=mod-a.x)>=mod) x-=mod; return *this; }
  mint& operator*=(const mint& a) { x=(unsigned long long)x*a.x%mod; return *this; }
  mint& operator/=(const mint& a) { x=(unsigned long long)x*a.pow(mod-2).x%mod; return *this; }
  mint operator+(const mint& a) const { return mint(*this) += a; }
  mint operator-(const mint& a) const { return mint(*this) -= a; }
  mint operator*(const mint& a) const { return mint(*this) *= a; }
  mint operator/(const mint& a) const { return mint(*this) /= a; }
  mint pow(long long t) const {
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a) const { return x < a.x; }
  bool operator==(const mint& a) const { return x == a.x; }
  bool operator!=(const mint& a) const { return x != a.x; }
};
istream& operator>>(istream& i, mint& a) { i>>a.x; return i; }
ostream& operator<<(ostream& o, const mint& a) { o<<a.x; return o; }

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<mint> a(n);
    for(mint& i:a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    mint res;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            mint add = a[i]*a[j];
            if(j-i>0) {
                add *= 1LL<<(j-i-1);
            }
            res += add;
        }
    }
    cout << res << '\n';
}