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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
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
    ll n,m;
    cin >> n >> m;
    vs s(n);
    rep(i,0,n)cin >> s[i];
    set<pair<ll,ll>> st;
    queue<pair<ll,ll>> q;
    q.push({1,1});
    st.insert({1,1});
    while(!q.empty()){
        pair<ll,ll> pos = q.front();q.pop();
        ll x = pos.first,y = pos.second;
        rep(i,x+1,n){
            if(s[i][y] == '.')st.insert({i-1,y});
            else{
                if(st.count({i-1,y}) == 0)q.push({i-1,y});
                st.insert({i-1,y});
                break;
            }
        }
        rrep(i,0,x){
            if(s[i][y] == '.')st.insert({i+1,y});
            else{
                if(st.count({i+1,y}) == 0)q.push({i+1,y});
                st.insert({i+1,y});
                break;
            }
        }
        rep(i,y+1,m){
            if(s[x][i] == '.')st.insert({x,i-1});
            else{
                if(st.count({x,i-1}) == 0)q.push({x,i-1});
                st.insert({x,i-1});
                break;
            }
        }
        rrep(i,0,y){
            if(s[x][i] == '.')st.insert({x,i+1});
            else{
                if(st.count({x,i+1}) == 0)q.push({x,i+1});
                st.insert({x,i+1});
                break;
            }
        }
    }
    cout << st.size() << endl;
}