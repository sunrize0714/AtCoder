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
    ll n,x,y,z;
    cin >> n >> x >> y >> z;
    vp mat(n),eng(n),tot(n);
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];
    rep(i,0,n){
        mat[i] = (make_pair(100-a[i],i+1));
        eng[i] = (make_pair(100-b[i],i+1));
        tot[i] = (make_pair(200-a[i]-b[i],i+1));
    }
    sort(mat.begin(),mat.end());
    sort(eng.begin(),eng.end());
    sort(tot.begin(),tot.end());
    set<ll> ans;
    rep(i,0,n){
        if(ans.size() == x)break;
        pair<ll,ll> pos = mat[i];
        ll p = pos.second; 
        ans.insert(p);
        if(ans.size() == x)break;
    }
    rep(i,0,n){
        if(ans.size() == x+y)break;
        pair<ll,ll> pos = eng[i];
        ll p = pos.second;
        ans.insert(p);
        if(ans.size() == x+y)break;
    }
    rep(i,0,n){
        if(ans.size() == x + y + z)break;
        pair<ll,ll> pos = tot[i];
        ll p = pos.second;
        ans.insert(p);
        if(ans.size() == x + y + z)break;
    } 
    while(ans.size() != 0){
        auto itr = ans.begin();
        cout << *(itr) << endl;
        ans.erase(*itr); 
    }
}