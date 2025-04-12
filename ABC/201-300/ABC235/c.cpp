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

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n,q;
    cin >> n >> q;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll s = a;
    sort(all(s));
    s.erase(unique(all(s)),s.end());
    vvll ans(s.size());
    rep(i,0,n){
        ll itr = lower_bound(all(s),a[i])-s.begin();
        ans[itr].push_back(i+1);
    }
    rep(i,0,q){
        ll x,k;
        cin >> x >> k;
        ll p = lower_bound(all(s),x)-s.begin();
        if(s[p] != x)cout << -1;
        else{
            if(ans[p].size() < k)cout << -1;
            else{
                cout << ans[p][k-1];
            }
        }
        cout << endl;
    }

}
