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
    ll n,m;
    cin >> n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll prime;
    rep(i,0,n){
        ll pos = a[i];
        rep(j,2,sqrt(a[i])+1){
            if(pos%j == 0){
                while(pos % j == 0){
                    pos /= j;
                }
                prime.push_back(j);
            }
        }
        if(pos != 1)prime.push_back(pos);
    }

    sort(prime.begin(),prime.end());
    prime.erase(unique(prime.begin(),prime.end()),prime.end());

    set<ll> ans;
    rep(i,1,m+1)ans.insert(i);
    
    rep(i,0,prime.size()){
        ll pos = prime[i];
        while(pos <= m){
            if(ans.count(pos) == 1)ans.erase(pos);
            pos += prime[i];
        }
    }

    cout << ans.size() << endl;
    auto itr = ans.begin();
    rep(i,0,ans.size()){
        cout << *(itr) << endl;
        itr++;
    }
}