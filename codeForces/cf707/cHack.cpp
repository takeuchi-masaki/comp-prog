  /*Ekeshwar JHoDE*/
#include<bits/stdc++.h>
#define M 1000000007
#define ff first
#define ss second
#define lup(i,a,b) for(ll i=a;i<=b;i++)
#define lupp(i,a,b) for(ll i=b;i>=a;i--)
#define vi vector<ll>
#define g1(a,b) __gcd(a,b)
#define bp(a)  __builtin_popcountll(a)
#define mp make_pair
#define pb push_back
#define vp vector<pair<ll,ll> >
#define ix INT_MAX
#define in INT_MIN
#define inf 1e18
#define st string
#define se set<ll>
#define mn1 map<ll,b>
#define vec vector<vector<ll> >
#define vt vector<ll>
#define so(a,n) sort(a,a+n)
#define so1(a,n) sort(a,a+n,greater<ll>())
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define sp(x) setprecision(x)
using namespace std;
typedef long long int ll;
ll c_p(ll a,ll n){
    ll ans=1;
    a%=M;
    if(a==0){
        return a;
    }
    while(n>0){
        if(n&1){
            ans=(ans*a)%M;
        }
        n=n>>1;
        a=(a*a)%M;
    }
    return ans;
}
/*void sieve_b(ll *b,ll max1){
    for(ll i=3;i<=max1;i+=2){
        b[i]=1;
    }
    for(ll i=3;i<=max1;i+=2){
        if(b[i]==1){
            for(ll j=i*i;j<=max1;j+=i){
                b[j]=0;
            }
        }
    }
    b[0]=b[1]=0;
    b[2]=1;
}*/
bool compare(const pair<ll,st>& x, const pair<ll,st>& y ){

    return (x.ff>y.ff);

}
struct b{
    ll x,y;
    b(ll a=0,ll b=0):x(a),y(b){};
};
vt answer(vt A);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   /* ll max1=2000000;
    ll b[max1]{0};
    sieve_b(b,max1);
    vi v;
    lup(i,0,max1){
        if(b[i]==1){
            v.push_back(i);
        }
    } */
    // cout<<v.size()<<'\n';
    /*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
    ll n;
    cin>>n;
    vt v(n);
    lup(i,0,n-1){
        cin>>v[i];
    }
    vt v1=answer(v);
    if(v1[0]==-2){
        cout<<"NO"<<'\n';
        return 0;
    }
    cout<<"YES"<<'\n';
    lup(i,0,v1.size()-1){
        cout<<v1[i]+1<<" ";
    }
    cout<<'\n';
    return 0;
}
vt answer(vt a){
    ll s,n=a.size(),x,y;
    vt a1;
    mn1 a3;
    lup(i,0,n-2){
        lup(j,i+1,n-1){
            s= a[i]+a[j];
            if(a3.find(s) == a3.end()){
                b t = b(i,j);
                a3[s] = t;
            }
            else{
                b t = a3[s];
                x = t.x, y = t.y;
                if(x != i && x != j && y != i && y != j){
                    a1.pb(i);a1.pb(j);a1.pb(x);a1.pb(y);
                    return a1;
                }
            }
        }
    }
    vt f;
    f.pb(-2);
    return f;
}






































