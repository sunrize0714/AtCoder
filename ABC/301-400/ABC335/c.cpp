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
    ll n,q;
    cin >> n >> q;
    vp ans(n);
    rep(i,0,n){
        ans[i] = make_pair(i+1,0);
    }
    ll cnt = n-1;

    rep(i,0,q){
        ll a;
        cin >> a;
        if(a == 1){
            char s;
            cin >> s;
            ans[cnt] = ans[(cnt+1)%n];
            if(s == 'R'){
                ans[cnt].first++;
            }
            if(s == 'L')ans[cnt].first--;
            if(s == 'U')ans[cnt].second++;
            if(s == 'D')ans[cnt].second--;

            if(cnt == 0)cnt = n-1;
            else cnt--;
        }
        else{
            ll c;
            cin >> c;
            c--;
            cout << ans[(c+cnt)%n].first << " " << ans[(c+cnt)%n].second << endl;
        }
    }
}