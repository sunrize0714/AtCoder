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
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m),c(m),d(m);
    rep(i,0,m)cin >> a[i] >> b[i];
    rep(i,0,m)cin >> c[i] >> d[i];
    vector<vb> a1(n,vb(n,false));
    vector<vb> a2(n,vb(n,false));

    rep(i,0,m){
        a[i]--,b[i]--,c[i]--,d[i]--;
        a1[a[i]][b[i]] = true;
        a1[b[i]][a[i]] = true;
        a2[c[i]][d[i]] = true;
        a2[d[i]][c[i]] = true;
    }
    vll array(n);
    rep(i,0,n)array[i] = i;
    do{
        bool f = true;
        rep(i,0,n){
            rep(j,0,n){
                if(a1[i][j] != a2[array[i]][array[j]])f = false;
            }
        }
        if(f){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(all(array)));
    cout << "No" << endl;
}