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
    ll q;
    cin >> q;
    queue<pair<ll,ll>> Q;
    ll used = 0;
    rep(i,0,q){
        ll key;
        cin >> key;
        if(key == 1){
            ll x,c;
            cin >> x >> c;
            Q.push(make_pair(x,c));
        }
        if(key == 2){
            ll c,ans = 0;
            cin >> c;
            while(c > 0){
                pair<ll,ll> pos = Q.front();
                if(c >= pos.second - used){
                    ans += pos.first*(pos.second - used);
                    Q.pop();
                    c -= pos.second - used;
                    used = 0;
                }
                else{
                    ans += pos.first*c;
                    used += c;
                    c = 0;
                }
            }
            cout << ans << endl;
        }
    }
}