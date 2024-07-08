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
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)a[i]--;
    vll siz(n,1);
    vll visited(n,-1);
    ll cnt = 0;
    while(cnt < n){
        if(visited[cnt] != -1)continue;
        ll pos = cnt;
        ll to = 0;
        visited[cnt] = 0;
        while(true){
            
        }
        cnt++;
    }
}