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
    vll a(n);
    rep(i,0,n)cin >> a[i];
    string s;
    cin >> s;
    vvll m(n+1,vll(3,0)),x(n+1,vll(3,0));
    rep(i,0,n){
        rep(j,0,3){
            if(s[i] == 'M' && a[i] == j)m[i+1][j] = m[i][j]+1;
            else m[i+1][j] = m[i][j];

            if(s[i] == 'X' && a[i] == j)x[i+1][j] = x[i][j]+1;
            else x[i+1][j] = x[i][j];
        }
    }
    ll ans = 0;
    rep(i,0,n){
        if(s[i] == 'E'){
            rep(j,0,3){
                rep(k,0,3){
                    rep(cnt,0,4){
                        if(a[i] != cnt && j != cnt && k != cnt){
                            ans += cnt*m[i][j]*(x[n][k]-x[i][k]);
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
