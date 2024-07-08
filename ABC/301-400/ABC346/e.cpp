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
    ll h,w,m;
    cin >> h >> w >> m;
    vll t(m),a(m),x(m);
    ll ver = h,hor = w;
    rep(i,0,m)cin >> t[i] >> a[i] >> x[i];
    map<ll,ll> t1,t2,ans;
    revrep(i,0,m){
        a[i]--;
        if(t[i] == 1){
            t1[a[i]]++;
            if(t1[a[i]] == 1){
                ans[x[i]] += hor;
                ver--;
            }
        }
        else{
            t2[a[i]]++;
            if(t2[a[i]] == 1){
                ans[x[i]] += ver;
                hor--;
            }
        }
    }
    ans[0] += hor*ver;
    vp p;
    x.push_back(0);
    sort(all(x));
    x.erase(unique(all(x)),x.end());
    rep(i,0,x.size()){
        if(ans[x[i]] != 0){
            p.push_back(make_pair(x[i],ans[x[i]]));
        }
    }
    sort(all(p));
    cout << p.size() << endl;
    rep(i,0,p.size())cout << p[i].first << " " << p[i].second << endl;
}