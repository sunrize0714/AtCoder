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
    ll h,w;
    cin >> h >> w;
    vvll a(h,vll(w)),b(h,vll(w));
    rep(i,0,h){
        rep(j,0,w)cin >> a[i][j];
    }
    rep(i,0,h){
        rep(j,0,w)cin >> b[i][j];
    }

    ll ans = 1e10;
    bool f = true;
    rep(i,0,h){
        rep(j,0,w){
            if(a[i][j] != b[i][j]){
                f = false;
                break;
            }
        }
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }

    vll tate(h),yoko(w);
    rep(i,0,h)tate[i] = i;
    rep(i,0,w)yoko[i] = i;

    do{
        do{
            bool ok = true;
            rep(i,0,h){
                rep(j,0,w){
                    if(a[tate[i]][yoko[j]] != b[i][j]){
                        ok = false;
                        break;
                    }
                }
                if(ok == false)break;
            }     
            if(ok){
                ll pos = 0;
                if(h > 1){
                    rep(i,0,h-1){
                        rep(j,i+1,h){
                            if(tate[i] > tate[j])pos++;
                        }
                    }
                }
                if(w > 1){
                    rep(i,0,w-1){
                        rep(j,i+1,w){
                            if(yoko[i] > yoko[j])pos++;
                        }
                    }
                }
                ans = min(ans,pos);
            }


        }while(next_permutation(yoko.begin(),yoko.end()));
        rep(i,0,w)yoko[i] = i;
    }while(next_permutation(tate.begin(),tate.end()));
    if(ans == 1e10)cout << -1 << endl;
    else cout << ans << endl;
}