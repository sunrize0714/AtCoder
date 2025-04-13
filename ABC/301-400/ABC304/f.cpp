#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = static_modint<998244353>;

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
    ll n;
    string s;
    cin >> n >> s;
    vll len;
    vector<mint> way;
    vector<mint> pow(n+1,1);
    rep(i,1,n+1)pow[i] = pow[i-1]*2;
    rep(i,1,n){
        if(n%i != 0)continue;
        vll absent(i,1);
        rep(j,0,n)if(s[j] == '.')absent[j%i] = 0;
        ll cnt = 0;
        rep(j,0,i)if(absent[j] == 1)cnt++;
        mint pos = pow[cnt];
        rep(j,0,len.size())if(i%len[j] == 0)pos -= way[j];
        len.push_back(i);
        way.push_back(pos);
    }
    mint ans = 0;
    rep(i,0,way.size())ans += way[i];
    cout << ans.val();
}
