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

int main(){
    ll n;
    string t;
    cin >> n >> t;
    string t2 = t;
    reverse(all(t2));
    vector<string> s(n);
    rep(i,0,n)cin >> s[i];
    vll ans;
    rep(i,0,n){
        ll pre = 0,suf = 0;
        ll a = s[i].size(),b = t.size();
        ll x=min(a,b);
        ll y = max(a,b);
        while(pre < x){
            if(s[i][pre] != t[pre])break;
            pre++;
        }
        reverse(all(s[i]));
        while(suf < x){
            if(s[i][suf] != t2[suf])break;
            suf++;
        }
        if(pre+suf >= y-1 && y-x <= 1)ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    rep(i,0,ans.size())cout << ans[i] << " ";
}