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
    ll a,b,x;
    cin >> a >> b >> x;
    ll pos = 1000000000;
    ll siz = 10;
    while(pos > 0){
        ll cost = pos * a + siz * b;
        if(cost > x){
            pos /= 10;
            siz--;
        }
        else{
            if(pos == 1000000000){
                cout << 1000000000 << endl;
                return 0;
            }
            else{
                ll ok = pos;
                ll ng = pos*10;
                while(abs(ok-ng)>1){
                    ll mid = (ok+ng)/2;
                    if(mid*a+siz*b > x){
                        ng = mid; 
                    }
                    else if(mid*a+siz*b<=x){
                        ok = mid;
                    }
                }
                cout << ok << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
}