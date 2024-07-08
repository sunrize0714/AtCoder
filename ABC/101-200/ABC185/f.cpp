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
            dat[pos] = dat[pos*2] ^ dat[pos*2+1];
        }
    }

    ll ans(ll l,ll r,ll a,ll b,ll u){
        if(r <= a || b <= l)return 0;
        if(l <= a && b <= r)return dat[u];
        ll m = (a+b)/2;
        ll AnsL = ans(l,r,a,m,u*2);
        ll AnsR = ans(l,r,m,b,u*2+1);
        return AnsL ^ AnsR;
    }

    ll get(ll n){
        return dat[n+siz-1];
    }

};

int main(){
    ll n,q;
    cin >> n >> q;
    vll a(n+1);
    rep(i,1,n+1)cin >> a[i];
    SegmentTree seg;
    seg.init(n);
    rep(i,1,n+1)seg.update(i,a[i]);
    rep(i,0,q){
        ll t,x,y;
        cin >> t >> x >> y;
        if(t == 1){
            ll pos = seg.get(x);
            seg.update(x,pos^y);
        }
        else{
            ll num = seg.ans(x,y+1,1,seg.siz+1,1);
            cout << num << endl;
        }
    }
}