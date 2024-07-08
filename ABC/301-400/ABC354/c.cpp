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

int main(){
    ll n;
    cin >> n;
    vll a(n),c(n);
    rep(i,0,n)cin >> a[i] >> c[i];
    vector<tuple<ll,ll,ll>> x;
    rep(i,0,n)x.push_back(make_tuple(c[i],a[i],i));
    sort(all(x));
    set<ll> st;
    rep(i,0,n)st.insert(i);
    ll cnt = get<1>(x[0]);
    rep(i,1,n){
        if(cnt > get<1>(x[i])){
            ll pos = get<2>(x[i]);
            st.erase(pos);
        }
        else{
            cnt = get<1>(x[i]);
        }
    }
    cout << st.size() << endl;
    auto itr = st.begin();
    rep(i,0,st.size()){
        cout << *itr+1 << " ";
        itr++;
    }
}