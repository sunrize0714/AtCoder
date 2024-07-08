#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

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
    ll n;
    cin >> n;
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];

    vll asize(n),bsize(n);
    map<ll,ll> ord;
    set<ll> s;
    rep(i,0,n){
        if(s.count(a[i]) == 0){
            s.insert(a[i]);
            ord[a[i]] = s.size();
        }
        asize[i] = s.size();
    }
    vll max_ind(n);

    s.clear();
    rep(i,0,n){
        if(ord[b[i]] == 0){
            max_ind[i] = 1e10+i;
        }
        else{
            if(i != 0)max_ind[i] = max(max_ind[i-1],ord[b[i]]);
            else max_ind[i] = ord[b[i]];
        }
        s.insert(b[i]);
        bsize[i] = s.size();
    }

    ll q;
    cin >> q;
    rep(i,0,q){
        ll x,y;
        cin >> x >> y;
        if(asize[x-1] != bsize[y-1]){
            cout << "No" << endl;
        }
        else{
            if(max_ind[y-1] == asize[x-1])cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}