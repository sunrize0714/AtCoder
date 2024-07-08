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
    vll a(5);
    rep(i,0,5){
        cin >> a[i];
    }
    ll array[5]={0,1,2,3,4};
    ll ans = 1e5;
    do{
        ll cnt = 0;
        rep(i,0,4){
            cnt += a[array[i]];
            while(cnt%10 != 0)cnt++;
        }
        cnt += a[array[4]];
        ans = min(ans,cnt);
    }while(next_permutation(array,array+5));
    cout << ans << endl;
}