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
    ll n,k;
    cin >> n >> k;
    vll c(n),v(n);
    rep(i,0,n)cin >> c[i] >> v[i];
    ll cnt = 0;
    rep(i,1,n){
        if(c[i-1] == c[i])cnt++;
    }
    if(cnt > k){
        cout << "-1" << endl;
        return 0;
    }
    else{
        vp p;
        ll ans = 0;
        p.push_back(make_pair(c[0],v[0]));
        ans += v[0];
        rep(i,1,n){
            if(c[i] == p.back().first){
                if(v[i] > p.back().second){
                    ans -= p.back().second;
                    p.pop_back();
                    p.push_back(make_pair(c[i],v[i]));
                    ans += v[i];
                    cnt++;
                }
            }
            else{
                p.push_back(make_pair(c[i],v[i]));
                ans += v[i];
            }
        }

        vp x;
        rep(i,0,p.size()){
            x.push_back(make_pair(p[i].second,i));
        }
        vll f(p.size()),b(p.size());
        f[0] = -1,b[p.size()-1] = 1e10;
        rep(i,0,p.size()){
            if(i != 0){
                f[i] = i-1;
            }
            if(i != p.size()-1){
                b[i] = i+1;
            }
        }
        k -= cnt;
        sort(all(x));
        rep(i,0,x.size()){
            if(k == 0)break;
            ll pos = x[i].second;
            if(f[pos] != -1 && b[pos] != 1e10){
                if(p[f[pos]].first == p[b[pos]].first){
                    continue;
                }
                else{
                    if(b[pos] != 1e10)f[b[pos]] = f[pos];
                    if(f[pos] != -1)b[f[pos]] = b[pos];
                    ans -= p[pos].second;
                    k--;
                }
            }
            else{
                if(b[pos] != 1e10)f[b[pos]] = f[pos];
                if(f[pos] != -1)b[f[pos]] = b[pos];
                ans -= p[pos].second;
                k--;
            }
            if(k == 0)break;
            if(i == x.size()-1){
                cout << -1 << endl;
                return 0;
            }
        }
        cout << ans << endl;
    }
}