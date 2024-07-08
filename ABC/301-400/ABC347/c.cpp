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
    ll n,a,b;
    cin >> n >> a >> b;
    vll d(n);
    rep(i,0,n)cin >> d[i];
    vll p;
    ll w = a+b;
    rep(i,0,n){
        p.push_back(d[i]%w);
    }
    sort(all(p));
    p.erase(unique(all(p)),p.end());
    if(p.size() == 1){
        cout << "Yes" << endl;
        return 0;
    }
    //rep(i,0,p.size())cout << p[i] << endl;
    rep(i,0,p.size()){
        ll pos = p[i];
        ll to;
        if(i!=0)to = i-1;
        else to = p.size()-1;
        ll x = p[to];
        if(x < pos)x += w;
        ll day = x-pos+1;
        if(day <= a){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No";
}