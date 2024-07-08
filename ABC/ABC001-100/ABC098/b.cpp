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
    string s;
    cin >> s;
    ll ans = 0;
    rep(i,1,s.size()-1){
        string t = s.substr(i,s.size()-i);
        string u = s.substr(0,i);

        map<char,ll> cnt1,cnt2;
        rep(j,0,u.size())cnt1[s[j]]++;
        rep(j,0,t.size())cnt2[t[j]]++;

        ll pos = 0;
        rep(j,0,26){
            char c = 'a' + j;
            if(cnt1[c] > 0 && cnt2[c] > 0)pos++;
        }
        ans = max(ans,pos);
    }
    cout << ans << endl;
}