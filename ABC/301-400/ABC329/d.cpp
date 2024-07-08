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
    vll a(m);
    rep(i,0,m)cin >> a[i];
    ll pos;
    map<ll,ll> vote;
    cout << a[0] << endl;
    vote[a[0]]++;
    pos = a[0];
    rep(i,1,m){
        vote[a[i]]++;
        if(vote[a[i]] > vote[pos]){
            pos = a[i];
            cout << pos << endl;
        }
        else if(vote[a[i]] == vote[pos]){
            if(pos > a[i]){
                pos = a[i];
                cout << pos << endl;
            }
        }
        else cout << pos << endl;
    }
}