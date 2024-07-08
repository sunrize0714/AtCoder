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
    string s;
    cin >> s;
    ll a[4];
    rep(i,0,4){
        a[i] = s[i] - '0';
    }
    rep(i,0,1<<3){
        vll op(4,1);
        vector<char> ops(4,'+');
        rep(j,1,4){
            if(i & (1<<(j-1))){
                op[j] *= -1;
                ops[j] = '-';
            }
        }
        ll pos = a[0];
        rep(j,1,4){
            pos += a[j]*op[j];
        }
        if(pos == 7){
            cout << a[0] << ops[1] << a[1] << ops[2] << a[2] << ops[3] << a[3] << "=7" << endl;
            return 0;
        }
    }
}