#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353

int main(){
    ll n;
    string s;
    cin >> n >> s;
    ll r = 0,w= 0;
    rep(i,0,n){
        if(s[i] == 'R')r++;
        else w++;
    }
    ll ans = 0;
    rep(i,r,n){
        if(s[i] == 'R')ans++;
    }
    cout << ans << endl;
}