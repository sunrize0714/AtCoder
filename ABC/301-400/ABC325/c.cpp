#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,0,h)cin >> s[i];
    ll ans = 0;
    vll dx ={1,1,0,-1,-1,-1,0,1};
    vll dy ={0,-1,-1,-1,0,1,1,1};
    queue<pair<ll,ll>> q;
    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] == '#'){
                q.push(make_pair(i,j));
                s[i][j] = '.';
                ans++;
                while(!q.empty()){
                    pair<ll,ll> pos = q.front();q.pop();
                    rep(k,0,8){
                        if(pos.first+dy[k] >= 0 && pos.first+dy[k]< h && pos.second+dx[k] >= 0 && pos.second + dx[k]<w)
                        if(s[pos.first + dy[k]][pos.second + dx[k]] == '#'){
                            q.push(make_pair(pos.first + dy[k],pos.second + dx[k]));
                            s[pos.first + dy[k]][pos.second + dx[k]] = '.';
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}