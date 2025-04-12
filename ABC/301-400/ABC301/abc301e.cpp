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
    ll h,w,t;
    cin >> h >> w >> t;
    vs a(h);
    rep(i,0,h)cin >> a[i];
    vll ame;
    ll sx,sy,gx,gy;
    rep(i,0,h){
        rep(j,0,w){
            if(a[i][j] == 'S'){
                sx = i,sy = j;
            }
            if(a[i][j] == 'G'){
                gx = i,gy = j;
            }
            if(a[i][j] == 'o'){
                ame.push_back(i*w+j);
            }
        }
    }
    ll cnt = ame.size();

    vvll ame_to_ame(cnt,vll(cnt,1e18));
    rep(i,0,cnt){
        vll dist(h*w,1e18);
        dist[ame[i]] = 0;
        queue<ll> q;
        q.push(ame[i]);
        while(!q.empty()){
            ll x = q.front()/w, y = q.front()%w;
            q.pop();
            rep(j,0,4){
                ll xx = x + dx4[j],yy = y + dy4[j];
                if(in_field(0,h,xx) && in_field(0,w,yy)){
                    if(a[xx][yy] != '#' && dist[xx*w+yy] > dist[x*w+y]+1){
                        q.push(xx*w+yy);
                        dist[xx*w+yy] = dist[x*w+y] + 1;
                    }
                }
            }
        }
        rep(j,0,cnt){
            ame_to_ame[i][j] = ame_to_ame[j][i] = min(ame_to_ame[i][j],dist[ame[j]]);
        }
    }

    vll pre(cnt,1e18),suf(cnt,1e18);
    vll dist(h*w,1e18);
    dist[sx*w+sy] = 0;
    queue<ll> q;
    q.push(sx*w+sy);
    while(!q.empty()){
        ll x = q.front()/w, y = q.front()%w;
        q.pop();
        rep(j,0,4){
            ll xx = x + dx4[j],yy = y + dy4[j];
            if(in_field(0,h,xx) && in_field(0,w,yy)){
                if(a[xx][yy] != '#' && dist[xx*w+yy] > dist[x*w+y]+1){
                    q.push(xx*w+yy);
                    dist[xx*w+yy] = dist[x*w+y] + 1;
                }
            }
        }
    }
    rep(i,0,cnt)pre[i] = dist[ame[i]];

    if(dist[gx*w+gy] > t){
        cout << -1;
        return 0;
    }

   
    rep(i,0,h*w)dist[i] = 1e18;
    dist[gx*w+gy] = 0;
    q.push(gx*w+gy);
    while(!q.empty()){
        ll x = q.front()/w, y = q.front()%w;
        q.pop();
        rep(j,0,4){
            ll xx = x + dx4[j],yy = y + dy4[j];
            if(in_field(0,h,xx) && in_field(0,w,yy)){
                if(a[xx][yy] != '#' && dist[xx*w+yy] > dist[x*w+y]+1){
                    q.push(xx*w+yy);
                    dist[xx*w+yy] = dist[x*w+y] + 1;
                }
            }
        }
    }
    rep(i,0,cnt)suf[i] = dist[ame[i]];

    vvll dp(1<<cnt,vll(cnt,1e9));
    rep(i,0,cnt)dp[1<<i][i] = pre[i];
    rep(i,0,1<<cnt){
        rep(j,0,cnt){
            if(dp[i][j] == 1e9)continue;
            rep(k,0,cnt){
                if(i & 1<<k)continue;
                if(dp[i | 1<<k][k] > dp[i][j] + ame_to_ame[j][k])dp[i | 1<<k][k] = dp[i][j] + ame_to_ame[j][k];
            }
        }
    }
    ll ans = 0;
    rep(i,1,1<<cnt){
        rep(j,0,cnt){
            if(dp[i][j] + suf[j] <= t){
                ll pos = 0;
                rep(k,0,cnt)if(i & 1<<k)pos++;
                ans = max(ans,pos);
            }
        }
    }
    cout << ans;
}