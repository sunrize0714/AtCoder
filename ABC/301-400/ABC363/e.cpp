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
    ll h,w,y;
    cin >> h >> w >> y;
    vvll a(h,vll(w));
    rep(i,0,h)rep(j,0,w)cin >> a[i][j];
    ll ans = h*w;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vvll used(h,vll(w,-1));
    rep(i,0,h){
        pq.push({a[i][0],i*w});
        if(w!=1)pq.push({a[i][w-1],i*w+w-1});
        used[i][0] = used[i][w-1] = 1;
    }
    rep(i,1,w-1){
        pq.push({a[0][i],i});
        if(h!=1)pq.push({a[h-1][i],w*(h-1)+i});
        used[0][i] = used[h-1][i] = 1;
    }
    ll cnt = 1;
    while(!pq.empty() & cnt <= y){
        ll t = pq.top().first, pos = pq.top().second;pq.pop();
        if(t > y)continue;
        ll x = pos/w,y = pos%w;
        if(cnt < t){
        while(cnt < t){
            cout << ans << endl;
            cnt++;
        }
        }
        if(cnt >= t)ans--;
        rep(i,0,4){
            ll xx = x+dx4[i],yy = y+dy4[i];
            if(in_field(0,h,xx) && in_field(0,w,yy)){
                if(used[xx][yy] == -1){
                    pq.push({a[xx][yy],xx*w+yy});
                    used[xx][yy] = 1;
                }
            }
        }
    }  
     while(cnt <= y){
        cout << ans << endl;
        cnt++;
    }
}