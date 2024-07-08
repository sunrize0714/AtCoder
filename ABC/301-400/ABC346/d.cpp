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

int main(){
    ll n;
    string s;
    cin >> n >> s;
    vll c(n);rep(i,0,n)cin >> c[i];
    ll cnt = 0;
    rep(i,1,n){
        if(s[i] == s[i-1])cnt++;
    }
        if(cnt == 1){
            cout << 0 << endl;
            return 0;
        }
    vvll cost1(n+1,vll(2,1e17));
    if(s[0] == '0'){cost1[1][0] = 0,cost1[1][1] = c[0];}
    else{
        cost1[1][0] = c[0],cost1[1][1] = 0;
    }
    rep(i,1,n){
        if(s[i] == '0'){
            cost1[i+1][0] = cost1[i][1];
            cost1[i+1][1] = cost1[i][0]+c[i];
        }
        else{
            cost1[i+1][1] = cost1[i][0];
            cost1[i+1][0] = cost1[i][1]+c[i];
        }
    }
    vvll cost2(n+1,vll(2,1e17));
    if(s[n-1] == '0'){
        cost2[n][0] = 0,cost2[n][1] = c[n-1];
    }
    else{
        cost2[n][0] = c[n-1],cost2[n][1] = 0;
    }
    revrep(i,1,n){
        if(s[i-1] == '0'){
            cost2[i][0] = cost2[i+1][1];
            cost2[i][1] = cost2[i+1][0]+c[i-1];
        }
        else{
            cost2[i][1] = cost2[i+1][0];
            cost2[i][0] = cost2[i+1][1]+c[i-1];
        }
    }
    ll ans = 1e17;
    rep(i,1,n){
        ans = min({ans,cost1[i][0]+cost2[i+1][0],cost1[i][1]+cost2[i+1][1]});
    }
    cout << ans << endl;
}