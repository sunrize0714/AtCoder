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


static ll dat[2000009];
class SegmentTree{
    public:
    //ll dat[2000009];
    ll siz = 1;

    void init(ll N){
        siz = 1;
        while(siz < N){
            siz *= 2;
        }
        rep(i,1,siz*2+1)dat[i] = 0;
    }

    void update(ll pos,ll x){
        pos = pos + siz - 1;
        dat[pos] = x;
        while(pos >= 2){
            pos /= 2;
            dat[pos] = min(dat[pos*2],dat[pos*2+1]);
        }
    }

    ll ans(ll l,ll r,ll a,ll b,ll u){
        if(r <= a || b <= l)return 1e18;
        if(l <= a && b <= r)return dat[u];
        ll m = (a+b)/2;
        ll AnsL = ans(l,r,a,m,u*2);
        ll AnsR = ans(l,r,m,b,u*2+1);
        return min(AnsL,AnsR);
    }

    ll get(ll n){
        return dat[n+siz-1];
    }

};

static ll dat2[2000009];
class SegmentTree2{
    public:
    //ll dat[2000009];
    ll siz2 = 1;

    void init(ll N){
        siz2 = 1;
        while(siz2 < N){
            siz2 *= 2;
        }
        rep(i,1,siz2*2+1)dat2[i] = 0;
    }

    void update(ll pos,ll x){
        pos = pos + siz2 - 1;
        dat2[pos] = x;
        while(pos >= 2){
            pos /= 2;
            dat2[pos] = max(dat2[pos*2],dat2[pos*2+1]);
        }
    }

    ll ans(ll l,ll r,ll a,ll b,ll u){
        if(r <= a || b <= l)return 0;
        if(l <= a && b <= r)return dat2[u];
        ll m = (a+b)/2;
        ll AnsL = ans(l,r,a,m,u*2);
        ll AnsR = ans(l,r,m,b,u*2+1);
        return max(AnsL,AnsR);
    }

    ll get(ll n){
        return dat2[n+siz2-1];
    }

};


int main(){
    ll n,k;
    cin >> n >> k;
    vll p(n);
    rep(i,0,n)cin >> p[i];
    if(k == 1)cout << 0 << endl;
    else{
        vll idx(n+1);
        rep(i,1,n+1){
            ll pos = p[i-1];
            idx[pos] = i;
        }
        SegmentTree seg;
        SegmentTree2 seg2;
        seg.init(n+1);
        seg2.init(n+1);
        rep(i,1,n+1){
            seg.update(i,idx[i]);
            seg2.update(i,idx[i]);
        }
        ll ans = 1e18;
        rep(i,1,n-k+2){
            ll cnt = seg.ans(i,i+k,1,seg.siz+1,1);
            ll cnt2 = seg2.ans(i,i+k,1,seg2.siz2+1,1);
            ans = min(ans,(cnt2-cnt));
        }
        cout << ans << endl;
    }
}