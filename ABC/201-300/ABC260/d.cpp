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
    ll n,k;
    cin >> n >> k;
    vll p(n);
    rep(i,0,n)cin >> p[i];
    set<ll> st;
    st.insert(-1);
    st.insert(1e18);
    vll on(n,-1),height(n,-1),ans(n,-1);
    rep(i,0,n){
        auto itr = st.lower_bound(p[i]-1);
        if(*itr == 1e18){
            st.insert(p[i]-1);
            height[p[i]-1] = 1; 
            if(k == 1){
                st.erase(p[i]-1);
                ans[p[i]-1] = i+1;
            }
        }
        else{
            on[p[i]-1] = *itr;
            height[p[i]-1] = height[*itr]+1;
            st.erase(*itr);
            if(height[p[i]-1] == k){
                ll pos = p[i]-1;
                rep(j,0,k){
                    ans[pos] = i+1;
                    pos = on[pos];
                }
            }
            else{
                st.insert(p[i]-1);
            }
        }
    }
    rep(i,0,n)cout << ans[i] << endl;
}