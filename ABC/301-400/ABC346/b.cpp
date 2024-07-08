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
    ll w,b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    string u = s;
    rep(i,0,30){
        s += u;
    }
    rep(i,0,15){
        ll x = w,y = b;
        rep(j,i+0,w+b+i){
            if(s[j] == 'w')x--;
            else y--;
        }
        if(x == 0 && y == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}