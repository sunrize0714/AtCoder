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

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

int main(){
    string s,t;
    cin >> s >> t;
    vector<pair<char,ll>> ss,tt;
    ss.push_back({s[0],1});
    tt.push_back({t[0],1});
    rep(i,1,s.size()){
        if(s[i] == ss.back().first){
            ll pos = ss.back().second;
            ss.pop_back();
            ss.push_back({s[i],pos+1});
        }
        else{
            ss.push_back({s[i],1});
        }
    }
    rep(i,1,t.size()){
        if(t[i] == tt.back().first){
            ll pos = tt.back().second;
            tt.pop_back();
            tt.push_back({t[i],pos+1});
        }
        else{
            tt.push_back({t[i],1});
        }
    }
    bool ans = true;
    if(ss.size() != tt.size())ans = false;
    if(ss.size() == tt.size())rep(i,0,ss.size()){
        if(ss[i].first != tt[i].first)ans = false;
        if(ss[i].second > tt[i].second)ans = false;
        if(ss[i].second == 1 && tt[i].second >= 2)ans = false;
    }
    if(ans)cout << "Yes";
    else cout << "No";
}
