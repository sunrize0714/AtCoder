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
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    n--;
    ll keta = 1;
    while(true){
        ll add = 9;
        ll cnt = 1;
        rep(i,0,(keta-1)/2)cnt *= 10;
        add *= cnt;
        if(add >= n){
            ll ans = n-1;
            ans += cnt;
            //cout << ans << " " << keta << " " << cnt << endl;
            string x;
            x = to_string(ans);
            string y = x;
            y = y.substr(0,keta/2);
            reverse(all(y));
            cout << x+y;
            return 0;
        }
        n -= add;
        keta++;
    }
}