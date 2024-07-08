#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    ll n;
    cin >> n;
    vll s(n),c(n);
    map<ll,bool> check;
    map<ll,ll> ma;
    priority_queue<ll,vll,greater<ll>> q;
    ll ans = 0;
    rep(i,0,n){
        cin >> s[i] >> c[i];
        check[s[i]] = true;
        ma[s[i]] = c[i];
        q.push(s[i]);
        ans += c[i];
    }
    
    while(!q.empty()){
        ll pos = q.top();q.pop();
        if(ma[pos] >= 2){
            ll now = ma[pos];
            ll to = pos;
            ll plus=0;
            ma[pos] = now%2;
            ans -= ma[pos]/2;
            while(now >= 2){
                plus = now%2;
                now /= 2;
                ans -= now;
                ma[to] = plus;
                to *= 2;
                now += ma[to];
            }
        }
    }

    cout << ans << endl;
    
}