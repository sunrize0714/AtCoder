#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    ll n;
    cin >> n;
    vs s(n);
    rep(i,0,n)cin >> s[i];
    vvvvll bfs(n,vvvll(n,vvll(n,vll(n,1e10))));
    vll p;
    ll cnt = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(s[i][j] == 'P'){
                p.push_back(i);
                p.push_back(j);
            }
        }
    }
    ll ans = 1e10;
    bfs[p[0]][p[1]][p[2]][p[3]] = 0;
    queue<tuple<ll,ll,ll,ll>> q;
    q.push(make_tuple(p[0],p[1],p[2],p[3]));
    while(!q.empty()){
        tuple<ll,ll,ll,ll> pos = q.front();q.pop();
        ll dist = bfs[get<0>(pos)][get<1>(pos)][get<2>(pos)][get<3>(pos)];

        rep(i,0,4){
            ll sx = get<0>(pos) + dy4[i];
            ll sy = get<1>(pos) + dx4[i];
            ll px = get<2>(pos) + dy4[i];
            ll py = get<3>(pos) + dx4[i];

            if(sx < 0 || sx >= n || sy < 0 || sy >= n){
                sx = get<0>(pos);
                sy = get<1>(pos);
            }
            else if(s[sx][sy] == '#'){
                sx = get<0>(pos);
                sy = get<1>(pos);
            }

            if(px < 0 || px >= n || py < 0 || py >= n){
                px = get<2>(pos);
                py = get<3>(pos);
            }
            else if(s[px][py] == '#'){
                px = get<2>(pos);
                py = get<3>(pos);
            }

            if(bfs[sx][sy][px][py] == 1e10){
                q.push(make_tuple(sx,sy,px,py));
                bfs[sx][sy][px][py] = dist+1;
            }
        }
    }

    rep(i,0,n){
        rep(j,0,n){
            if(bfs[i][j][i][j] != 1e10)ans = min(ans,bfs[i][j][i][j]);
        }
    }
    if(ans == 1e10)cout << -1;
    else cout << ans << endl;
}