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


int main(){
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vector<string> ans(200,"");
    ll len = min(n,8LL);
    rep(idx,1,1LL<<len){
        ll pos = idx;
        ll s = 0;
        string x;
        rep(i,0,len){
            if(idx & 1LL<<i){
                x += '1';
                s += a[i];
            }
            else x += '0';
        }
        if(ans[s%200] != ""){
            cout << "Yes" << endl;
            vll b,c;
            rep(i,0,len){
                if(x[i] == '1')b.push_back(i+1);
                if(ans[s%200][i] == '1')c.push_back(i+1);
            }
            cout << b.size() << " ";
            rep(i,0,b.size())cout << b[i] << " ";
            cout << endl << c.size() << " ";
            rep(i,0,c.size())cout << c[i] << " ";
            cout << endl;
            return 0;
        }
        else{
            ans[s%200] = x;
        }
    }
    cout << "No" << endl;
}
