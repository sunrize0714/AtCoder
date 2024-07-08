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
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    ll ok = 0,ng = 1e17;
    vvll appear(s.size(),vll(26,0));
    vvll up(26);
    rep(i,0,s.size()){
        rep(j,0,26){
            if(s[i] == 'a'+j){
                appear[i][j]++;
                up[j].push_back(i);
            }
        }
    }
    rep(i,1,s.size()){
        rep(j,0,26)appear[i][j] += appear[i-1][j];
    }
    while(abs(ok-ng)>1){
        bool f = true;
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        ll roop = 0;
        rep(i,0,t.size()){
            if(appear[s.size()-1][t[i]-'a'] == 0){
                f = false;
                break;
            }
            ll left = mid; 
            ll first;
            if(cnt != 0){
                first = appear[s.size()-1][t[i]-'a'] - appear[cnt-1][t[i]-'a'];
            }
            else first =  appear[s.size()-1][t[i]-'a'];
            if(first >= left){
                ll pos = lower_bound(all(up[t[i]-'a']),cnt+1) - up[t[i]-'a'].begin();
                cnt = up[t[i]-'a'][pos + left];
                if(cnt == s.size()){
                    roop++;
                    cnt = 0;
                }
            }
            else{
                left -= first;
                roop++;
                ll roops = left/(appear[s.size()-1][t[i]-'a']) + (left%appear[s.size()-1][t[i]-'a'] != 0);
                roop += roops;
    ll pos = lower_bound(all(up[t[i]-'a']),cnt+1) - up[t[i]-'a'].begin();
                cnt = up[t[i]-'a'][pos + left];
                if(cnt == s.size()){
                    roop++;
                    cnt = 0;
                }
            }
            if(roop >= n)f = false;
        }
        if(f)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}