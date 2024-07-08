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

ll dist(pair<ll,ll> a,pair<ll,ll> b){
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
    vs s(9);
    rep(i,0,9)cin >> s[i];
    vp point;
    rep(i,0,9){
        rep(j,0,9){
            if(s[i][j] == '#'){
                point.push_back(make_pair(i,j));
            }
        }
    }
    if(point.size() <= 3){
        cout << 0 << endl;
        return 0;
    }
    ll n = point.size();
    ll ans = 0;
    rep(i,0,n-3){
        rep(j,i+1,n-2){
            rep(k,j+1,n-1){
                rep(l,k+1,n){
                    pair<ll,ll> v[4] = {point[i],point[j],point[k],point[l]};
                    vll a;
                    rep(m,0,3){
                        rep(o,m+1,4){
                            a.push_back(dist(v[m],v[o]));
                        }
                    }
                    sort(all(a));
                    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] == 2*a[3] && a[4] == a[5])ans++;
                }
            }
        }
    }
    cout << ans << endl;
}