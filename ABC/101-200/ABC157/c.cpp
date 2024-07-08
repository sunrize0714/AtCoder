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

int main(){
    ll n,m;
    cin >> n >> m;
    vll ans(n,-1);
    rep(i,0,m){
        ll s,c;
        cin >> s >> c;
        s--;
        if(ans[s] == -1)ans[s] = c;
        else if(ans[s] != c){
            cout << -1 << endl;
            return 0;
        }

        if(n != 1 && ans[0] == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    string t;
    rep(i,0,n){
        if(ans[i] == -1){
            if(i == 0 && n != 1)ans[i] = 1;
            else if(n == 1)ans[i] = 0;
            else ans[i] = 0;
        }
        char u = '0' + ans[i];
        t += u;
    }
    cout << t << endl;
}