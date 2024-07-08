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
    double x,y;
    cin >> x >> y;
    double under = sqrt(x*x+y*y)/2.0;
    if(x == 0.0 || y == 0.0){
        if(abs(x) == 1.0){
            cout << "0 2";
            return 0;
        }
        else if(abs(y) == 1.0){
            cout << "2 0";
            return 0;
        }
        else if(abs(x) == 2.0){
            cout << "0 1";
            return 0;
        }
        else if(abs(y) == 2.0){
            cout << "1 0";
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }
    }

    double m = y/x;
    double th = acos(x/under);
    under = 1.0/under;
    double d = under/cos(th);
    
}