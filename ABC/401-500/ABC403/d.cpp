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
    ll n,d;
    cin >> n >> d;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    sort(all(a));
    vll b = a;
    b.erase(unique(all(b)),b.end());


    vll p(b.size(),0);
    rep(i,0,n){
        ll itr = lower_bound(all(b),a[i]) - b.begin();
        p[itr]++;
    }

    if(d == 0){
        ll ans = 0;
        rep(i,0,p.size()){
            ans += p[i]-1;
        }
        cout << ans;
        return 0;
    }

    vll next(b.size(),-1);
    rep(i,0,b.size()){
        ll pos = b[i] + d;
        ll itr = lower_bound(all(b),pos) - b.begin();
        if(b[itr] == pos){
            next[i] = itr;
        }
    }

    
    //rep(i,0,b.size())cout << b[i] << " " << p[i] << " " << next[i] << endl;

    ll ans = n;
    vll visited(b.size(),false);
    ll cnt = 0;
    while(cnt < b.size()){
        ll pos = cnt;
        vll x;
        while(!visited[pos]){
            visited[pos] = true;
            x.push_back(p[pos]);

            if(next[pos] != -1){
                pos = next[pos];
            }
        }
        ll tmp = x.size();
        if(tmp > 0){
        //rep(i,0,x.size())cout << x[i] << endl;


        vvll dp(tmp,vll(2,0));
        dp[0][0] = 0,dp[0][1] = x[0];
        rep(i,1,tmp){
            dp[i][0] = max({dp[i][0],dp[i-1][0],dp[i-1][1]});
            dp[i][1] = max({dp[i][1],dp[i-1][0] + x[i]});
        }
        ans -= max(dp[tmp-1][0],dp[tmp-1][1]);
        }
        cnt++;
    }
    cout << ans;
}
