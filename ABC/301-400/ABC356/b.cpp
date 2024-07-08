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

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(m);
    rep(i,0,m)cin >> a[i];
    vvll x(n,vll(m));
    rep(i,0,n)rep(j,0,m)cin >> x[i][j];
    rep(i,1,n){
        rep(j,0,m){
            x[i][j] += x[i-1][j];
        }
    }
    rep(i,0,m){
        if(x[n-1][i] < a[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}