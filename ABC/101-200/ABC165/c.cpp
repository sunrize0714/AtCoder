#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}
ll n,m,q;
ll a[60],b[60],c[60],d[60];
ll A[11];
ll ans = 0;

void dfs(ll cnt,ll pos){
    if(cnt == n){
        ll sco = 0;
        rep(i,0,q){
            if(A[b[i]]-A[a[i]] == c[i])sco+= d[i];
        }
        ans=max(ans,sco);
        return;
    }
    rep(i,pos,m+1){
        A[cnt] = i;
        dfs(cnt+1,i);
    }
}
int main(){
    cin >> n >> m >> q;
    rep(i,0,q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--,b[i]--;
    }
    dfs(0,1);
    cout << ans << endl;
}