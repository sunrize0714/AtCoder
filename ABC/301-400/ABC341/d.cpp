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
    ll n,m,k;
    cin >> n >> m >> k;
    if(n > m)swap(n,m);
    ll x = lcm(n,m);
    ll cnt = x/n + x/m - 2;
    ll cy = k/cnt;
    ll ans = cy*x;
    if(k%cnt == 0){
        ans -= n;
        cout << ans << endl;
        return 0;
    }
    k -= cy*cnt;
    priority_queue<ll,vll,greater<ll>> q;
    q.push(ans+n);
    q.push(ans+m);
    if(k == 1){
        ans += n;
        cout << ans << endl;
        return 0;
    }
    rep(i,0,k-1){
        ll pos = q.top();q.pop();
        if(pos%n == 0){
            q.push(pos + n);
        }
        else q.push(pos+m);
    }
    cout << q.top() << endl;
}