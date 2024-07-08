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
            dat[pos] = max(dat[pos*2],dat[pos*2+1]);
        }
    }

    ll ans(ll l,ll r,ll a,ll b,ll u){
        if(r <= a || b <= l)return -1e17;
        if(l <= a && b <= r)return dat[u];
        ll m = (a+b)/2;
        ll AnsL = ans(l,r,a,m,u*2);
        ll AnsR = ans(l,r,m,b,u*2+1);
        return max(AnsL,AnsR);
    }

    ll get(ll n){
        return dat[n+siz-1];
    }

};


int main(){
    ll n,d;
    cin >> n >> d;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    SegmentTree seg;
    seg.init(500001);
    rep(i,0,n){
        ll l = max(1LL,a[i]-d);
        ll r = min(500001LL,a[i]+d+1);
        ll pos = seg.ans(l,r,1,seg.siz+1,1);
        seg.update(a[i],pos+1);
    }
    ll x = 0;
    rep(i,1,500001)x = max(x,seg.get(i));
    cout << x << endl;
}
