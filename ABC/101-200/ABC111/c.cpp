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
    ll n;
    cin >> n;
    vll v1(n/2),v2(n/2);
    map<ll,ll> a1,a2;
    ll maxi1=-1,maxi2=-1;
    rep(i,0,n/2){
        cin >> v1[i] >> v2[i];
        a1[v1[i]]++;
        if(a1[maxi1] < a1[v1[i]])maxi1 = v1[i];
        a2[v2[i]]++;
        if(a2[maxi2] < a2[v2[i]])maxi2 = v2[i];
    }

    if(maxi1 != maxi2){
        cout << n - a1[maxi1] -a2[maxi2];
    }
    else{
        ll maxi11 = -1,maxi22 = -1;
        rep(i,0,n/2){
            if(a1[maxi11] < a1[v1[i]] && v1[i] != maxi1){
                maxi11 = v1[i];
            }
            if(a2[maxi22] < a2[v2[i]] && v2[i] != maxi2){
                maxi22 = v2[i];
            }
        }
        ll ans = max(a1[maxi1]+a2[maxi22],a2[maxi2]+a1[maxi11]);
        cout << n - ans << endl;
    }
    
}