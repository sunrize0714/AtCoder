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

int main(){
    ll n;
    string s;
    ll q;
    cin >> n >> s >> q;
    vector<char> c(q),d(q);
    rep(i,0,q)cin >> c[i] >> d[i];
    vll st(26);
    rep(i,0,26)st[i] = i;
    rep(i,0,q){
        ll x = c[i] - 'a';
        ll y = d[i] - 'a';
        rep(j,0,26){
            if(st[j] == x){
                st[j] = y;
            }
        }
    }
    rep(i,0,s.size()){
        ll pos = s[i] - 'a';
        char t = 'a' + st[pos];
        cout << t;
    }
}