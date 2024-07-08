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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    ll ans = 0;
    vll last(n,-1),candy(n,0);
    ll pos = 0;
    ll cnt = k;
    while(cnt > 0){
        if(last[pos] != -1){
            ll roop = cnt/((n-cnt)-last[pos]);
            if(roop > 0){
                ans += roop*(ans-candy[pos]);
                cnt -= roop*((n-cnt)-last[pos]);
            }
            else{
                while(cnt > 0){
                    pos = ans%n;
                    ans+=a[pos];
                    cnt--;
                }
            }
        }
        else{
            last[pos] = n-cnt;
            candy[pos] = ans;
            ans += a[pos];
            pos = ans%n;
            cnt--;
        }
    }
    cout << ans << endl;
}