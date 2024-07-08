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
    ll h,w,R,C;
    cin >> h >> w >> R >> C;
    ll n,q;
    vvll mas_h(w+1),mas_w(h+1);
    vll r(n),c(n),l(q);
    vector<char> d(q);  
    cin >> n;
    rep(i,0,n){
        cin >> r[i] >> c[i];
        mas_h[c[i]].push_back(r[i]);
        mas_w[r[i]].push_back(c[i]);
    }
    cin >> q;
    rep(i,0,q){
        if(d[i] == 'L'){
            ll to = R + l[i];
            if(to > w)to = w;
            if(mas_h[C].size() == 0){
                R = to;
                cout << R << " " << C << endl; 
            }
            else{
                auto itr = lower_bound(mas_h[C].begin(),mas_h[C].end(),R) - mas_h[C].begin();
                R = mas_h[C][itr]-1;
                cout << R << " " << C << endl;
            }
        }
        if(d[i] == 'R'){
            ll to = R - l[i];
            if(to < 1)to = 1;
            if(mas_h[C].size() == 0){
                R = to;
                cout << R << " " << C << endl; 
            }
            else{
                auto itr = lower_bound(mas_h[C].begin(),mas_h[C].end(),to) - mas_h[C].begin();
                R = mas_h[C][itr]+1;
                cout << R << " " << C << endl;
            }
        }
        if(d[i] == 'U'){
            ll to = C - l[i];
            if(to < 1)to = 1;
            if(mas_w[R].size() == 0){
                C = to;
                cout << R << " " << C << endl; 
            }
            else{
                auto itr = lower_bound(mas_w[R].begin(),mas_w[R].end(),to) - mas_w[R].begin();
                C = mas_w[R][itr]+1;
                cout << R << " " << C << endl;
            }
        }
        if(d[i] == 'D'){
            ll to = C + l[i];
            if(to > h)to = h;
            if(mas_w[R].size() == 0){
                C = to;
                cout << R << " " << C << endl; 
            }
            else{
                auto itr = lower_bound(mas_w[R].begin(),mas_w[R].end(),to) - mas_w[R].begin();
                C = mas_w[R][itr]-1;
                cout << R << " " << C << endl;
            }
        }
    }
}