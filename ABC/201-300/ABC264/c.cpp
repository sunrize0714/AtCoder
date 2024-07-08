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

int main(){
    ll h1,w1;
    cin >> h1 >> w1;
    vvll a(h1,vll(w1));
    rep(i,0,h1)rep(j,0,w1)cin >> a[i][j];
    ll h2,w2;
    cin >> h2 >> w2;
    vvll b(h2,vll(w2));
    rep(i,0,h2)rep(j,0,w2)cin >> b[i][j];

    rep(i,0,1<<h1){
        rep(j,0,1<<w1){
            vll ans;
            rep(k1,0,h1){
                rep(k2,0,w1){
                    if(i & 1 << k1 && j & 1 << k2)ans.push_back(a[k1][k2]);
                }
            }
            if(ans.size() != h2*w2)continue;
            bool ok = true;
            rep(k,0,ans.size()){
                if(ans[k] != b[k/w2][k%w2]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}