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
    ll n,q;
    cin >> n >> q;
    vs p(n);
    rep(i,0,n){
        cin >> p[i];
    }

    vvll wa(n+1,vll(n+1,0));

    rep(i,0,n){
        rep(j,0,n){
            wa[i+1][j+1] += (p[i][j] == 'B');
        }
    }

    rep(i,0,n+1){
        rep(j,1,n+1){
            wa[i][j] += wa[i][j-1];
        }
    }

    rep(i,1,n+1){
        rep(j,1,n+1){
            wa[i][j] += wa[i-1][j];
        }
    }
    rep(i,0,q){
        ll ans = 0;
        ll a,b,c,d;
        cin >> a >> b >> c >> d;

        ll yoko = d-b - d%n  - (n - b%n);
        ll tate = c-a - c%n - (n - a%n);
        tate /= n,yoko /= n;
        ans += (wa[0][0] + wa[n][n] - wa[0][n] - wa[n][0])*(tate*yoko);
        //cout << ans  << " "  << tate << " " << yoko << endl;
        ll A,B,C,D;
        A = a%n,B = b%n,C = c%n,D = d%n;
        ans += wa[A][B] + wa[n][n] - wa[A][n]- wa[n][B];
        if(yoko > 0){
            if(A!=0)ans += (wa[A][0] + wa[n][n] -wa[A][n] -wa[n][0])*yoko;
            if(C!=0)ans += (wa[0][0] + wa[C+1][n] -wa[0][n] - wa[C+1][0])*yoko;
        }
        if(tate > 0){
            if(B!=0)ans += (wa[0][B] + wa[n][n] - wa[0][n] - wa[n][B])*tate;
            if(D!=0)ans += (wa[0][0] + wa[n][D+1] - wa[0][D+1] - wa[n][0])*tate;
        }
        if(A!=0)ans += wa[A][0] + wa[n][D+1]- wa[A][D+1]-wa[n][0];
        if(C!=0)ans += wa[0][0] + wa[C+1][D+1]- wa[0][D+1]-wa[C+1][0];
        if(C!=0)ans += wa[0][B] + wa[C+1][n]- wa[0][n]-wa[C+1][B];

        cout << ans << endl;
    }

}