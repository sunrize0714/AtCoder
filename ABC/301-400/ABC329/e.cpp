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
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    queue<ll> q;
    set<ll> a;
    rep(i,0,n-m+1){
        bool ok = true;
        rep(j,0,m){
            if(s[i+j] != t[j])ok = false;
        }
        if(ok){
            q.push(i);
            a.insert(i);
        }
    }
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,pos,pos+m)s[i] = '#';
        ll to = min(pos+m-1,n-m);
        pos = max(pos-m+1,0LL);
        rep(i,pos,to+1){
            if(a.count(i) == 1)continue;
            bool ok = true;
            rep(j,0,m){
                if(s[i+j] != '#' && s[i+j] != t[j])ok = false;
            }
            if(ok){
                q.push(i);
                a.insert(i);
            }
        }
    }
    string x;
    rep(i,0,n)x += '#';
    s == x ? cout << "Yes" << endl: cout << "No" << endl;
}