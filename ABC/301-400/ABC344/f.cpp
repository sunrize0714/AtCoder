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
    vvll p(n,vll(n));
    rep(i,0,n)rep(j,0,n)cin >> p[i][j];
    vvll r(n,vll(n-1));
    rep(i,0,n)rep(j,0,n-1)cin >> r[i][j];
    vvll d(n-1,vll(n));
    rep(i,0,n-1)rep(j,0,n)cin >> d[i][j];
    vll turn(n*n,1e15);
    turn[0] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vb ok(n*n,false);
    pq.push(make_pair(r[0][0],1));
    pq.push(make_pair(d[0][0],n));
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        if(ok[pos])continue;
        ok[pos] = true;
        if(pos%n != n-1){
            if(turn[pos+1] > turn[pos] + r[pos/n][pos%n]){
                turn[pos+1] = turn[pos] + r[pos/n][pos%n];
                pq.push(make_pair(turn[pos+1],pos+1));
            }
        }
        if(pos/n != n-1){
            if(turn[pos+n] > turn[pos] + d[pos/n+1][pos%n]){
                turn[pos+n] = turn[pos] + d[pos/n+1][pos%n];
                pq.push(make_pair(turn[pos+n],pos+n));
            }
        }
    }
    
}