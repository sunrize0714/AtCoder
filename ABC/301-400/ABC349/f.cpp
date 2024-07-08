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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

vector<pair<ll,ll>> ans;
void dfs(ll L,ll R,ll l,ll r){
    if(R <= l || r <= L)return;
    if(L <= l && r <= R)ans.push_back(make_pair(l,r));
    else{
        ll mid = (l+r)/2;
        dfs(L,R,l,mid);
        dfs(L,R,mid,r);
    }
}

int main(){
    ll l,r;
    cin >> l >> r;
    dfs(l,r,0,1LL<<60);
    cout << ans.size() << endl;
    rep(i,0,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}