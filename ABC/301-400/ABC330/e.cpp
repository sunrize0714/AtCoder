#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
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
    vector<set<ll>> se(n); 
    set<ll> zero;
    rep(i,0,n){
        cin >> a[i];
        if(a[i] < n)se[a[i]].insert(i);
    }
    
    rep(i,0,n+1){
        if(se[i].size() == 0)zero.insert(i);
    }
    ll ans = n;
    rep(i,0,n){
        if(se[i].size()==0){
            ans = i;
            break;
        }
    }
    
    rep(i,0,q){
        ll I,x;
        cin >> I >> x;
        I--;
        ll pos = a[I];
        if(pos < n){
            se[pos].erase(I);
            if(se[pos].size() == 0){
                zero.insert(pos);
                ans = min(ans,pos);
            }
        }
        if(x < n){
            if(se[x].size() == 0)zero.erase(x);
            se[x].insert(I);
            if(se[ans].size() != 0){
                auto itr = zero.begin();
                ans = *itr;
            }
        }
        a[I] = x;
        cout << ans << endl;
    }
}