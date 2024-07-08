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
    ll h,w,c;
    cin >> h >> w >> c;
    vvll a(h,vll(w));
    rep(i,0,h){
        rep(j,0,w)cin >> a[i][j];
    }
    vvll copy(h,vll(w));
    rep(i,0,h){
        rep(j,0,w)copy[i][j] = a[i][j];
    }
    ll ans = 1e18;
    vll cost;
    rep(i,0,h){
        rep(j,0,w){
            copy[i][j] += c*i;
            copy[i][j] += c*j;
            //cout << copy[i][j] << " ";
            cost.push_back(copy[i][j]);
        }
        //cout << endl;
    }
    sort(cost.begin(),cost.end());
    rep(i,1,cost.size()){
        ans = min(ans,cost[i]-cost[i-1]);
    }

    rep(i,0,h){
        rep(j,0,w)copy[i][j] = a[i][j];
    }
    vll cost2;
    rep(i,0,h){
        rep(j,0,w){
            copy[i][j] += c*(w-1-j);
            copy[i][j] += c*i;
            cost2.push_back(copy[i][j]);
        }
    }
    sort(cost2.begin(),cost2.end());
    rep(i,1,cost2.size()){
        ans = min(ans,cost2[i]-cost2[i-1]);
    }
    
    vll cost3;
    rep(i,0,h){
        rep(j,0,w)copy[i][j] = a[i][j];
    }
    rep(i,0,h){
        rep(j,0,w){
            copy[i][j] += c*(w-1-j);
            copy[i][j] += c*(h-1-i);
            cost3.push_back(copy[i][j]);
        }
    }
    sort(cost3.begin(),cost3.end());
    rep(i,1,cost3.size()){
        ans = min(ans,cost3[i]-cost3[i-1]);
    }

    rep(i,0,h){
        rep(j,0,w)copy[i][j] = a[i][j];
    }
    vll cost4;
    rep(i,0,h){
        rep(j,0,w){
            copy[i][j] += c*(h-1-i);
            copy[i][j] += c*j;
            cost4.push_back(copy[i][j]);
        }
    }
    sort(cost4.begin(),cost4.end());
    rep(i,1,cost4.size()){
        ans = min(ans,cost4[i]-cost4[i-1]);
    }
    cout << ans << endl;
}