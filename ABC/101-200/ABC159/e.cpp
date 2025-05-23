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
    ll h,w,k;
    cin >> h >> w >> k;
    vs s(h);
    rep(i,0,h)cin >> s[i];

    ll ans = 10000;
    rep(i,0,(1 << (h-1))){
        vll cut;
        rep(j,0,h-1){
            if(i & (1 << j)){
                cut.push_back(j);
            }
        }
        cut.push_back(h-1);

        vll wa(cut.size(),0);
        vvll retu(cut.size(),vll(w,0));
        bool ok = true;
        rep(i,0,h){
            rep(j,0,w){
                auto itr = lower_bound(cut.begin(),cut.end(),i) - cut.begin();
                if(s[i][j] == '1')retu[itr][j]++;
                if(retu[itr][j] > k){
                    ok = false;
                    break;
                }
            }
            if(!ok)break;
        }
        
        if(!ok)continue;
        ll cnt = cut.size()-1;

        rep(i,0,w){
            bool f = true;
            rep(j,0,cut.size()){
                wa[j] += retu[j][i];
                if(wa[j] > k){
                    f = false;
                }
            }

            if(!f){
                cnt++;
                rep(j,0,cut.size()){
                    wa[j] = retu[j][i];
                }
            }
        }

        ans = min(ans,cnt);
    }
    cout << ans << endl;
}