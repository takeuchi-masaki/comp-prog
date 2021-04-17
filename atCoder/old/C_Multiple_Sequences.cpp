#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
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

int N, M;
mint res;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        
    }
    cout << res << '\n';
}