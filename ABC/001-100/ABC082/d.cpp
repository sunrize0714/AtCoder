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
    string s;
    cin >> s;
    ll x,y;
    cin >> x >> y;
    vll hor,var;
    bool h = true;
    ll cnt = 0;
    rep(i,0,s.size()){
        if(s[i] == 'F'){
            cnt++;
        }
        else{
            if(h)hor.push_back(cnt);
            else var.push_back(cnt);
            cnt = 0;
            h = !h;
        }
    }
    if(h)hor.push_back(cnt);
    else var.push_back(cnt);

    bool ok = true;
    cnt = 0;
    x -= hor[0];
    x = abs(x);
    rep(i,1,hor.size()){
        cnt += hor[i];
    }
    if(x > cnt)ok = false;
    if((cnt-x)%2 == 1)ok = false;
    x += (cnt-x)/2;
    vb dp(cnt+1,false);
    dp[0] = true;
    rep(i,1,hor.size()){
        revrep(j,hor[i],cnt+1){
            if(dp[j-hor[i]])dp[j] = true;
        }
    }
    if(!dp[x])ok = false;

    cnt = 0;
    y = abs(y);
    rep(i,0,var.size()){
        cnt += var[i];
    }
    if(y > cnt)ok = false;
    if((cnt-y)%2 == 1)ok = false;
    y += (cnt-y)/2;
    vb dp2(cnt+1,false);
    dp2[0] = true;
    rep(i,0,var.size()){
        revrep(j,var[i],cnt+1){
            if(dp2[j-var[i]])dp2[j] = true;
        }
    }
    if(!dp2[y])ok = false;
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}