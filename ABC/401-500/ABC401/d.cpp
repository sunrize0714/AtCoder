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

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n,k;
    string s;
    cin >> n >> k >> s;
    string ans = s;

    rep(i,0,n){
        if(s[i] != '?')continue;
        bool ok = true;
        if(i != 0)if(s[i-1] == 'o')ok = false;
        if(i != n-1)if(s[i+1] == 'o')ok = false;
        if(!ok)ans[i] = '.';
    }
    ll left = k;
    rep(i,0,n)if(s[i] == 'o')left--;

    if(left == 0){
        rep(i,0,n)if(ans[i] == '?')ans[i] = '.';
        cout << ans;
        return 0;
    }

    ll can = 0;
    ll cnt = 0;
    rep(i,0,n){
        if(ans[i] != '?'){
            can += (cnt+1)/2;
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    can += (cnt+1)/2;
    if(can != left)cout << ans;
    else{
        cnt = 0;
        ll idx = -1;
        rep(i,0,n){
            if(ans[i] != '?'){
                if(cnt > 0 && cnt%2 == 1){
                    rep(j,idx,i){
                        if((j-idx)%2 == 0)ans[j] = 'o';
                        else ans[j] = '.';
                    }
                }
                cnt = 0;
                idx = -1;
            }
            else{
                if(idx == -1)idx = i;
                cnt++;
            }
        }
        if(idx != -1){
            if(cnt > 0 && cnt%2 == 1){
                rep(j,idx,n){
                    if((j-idx)%2 == 0)ans[j] = 'o';
                    else ans[j] = '.';
                }
            }
        }
        cout << ans;
    }
}
