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

ll h,w,a,b;
ll ans = 0;

void dfs(vvll &m,ll a,ll b,ll from){
    if(a == 0 & b == 0)ans++;
    else{
        rep(i,0,h)rep(j,0,w){
            if(i*w+j <= from)continue;
            if(m[i][j] == 0){
                if(a > 0){
                    if(in_field(0,w,j+1) & m[i][j+1] == 0){
                        m[i][j] = m[i][j+1] = 1;
                        dfs(m,a-1,b,i*w+j);
                        m[i][j] = m[i][j+1] = 0;
                    }
                    if(in_field(0,h,i+1) & m[i+1][j] == 0){
                        m[i+1][j] = m[i][j] = 1;
                        dfs(m,a-1,b,i*w+j);
                        m[i+1][j] = m[i][j] = 0;
                    }
                }
                if(b > 0){
                    m[i][j] = 1;
                    dfs(m,a,b-1,i*w+j);
                    m[i][j] = 0;
                }
            }
        }
    }
}

int main(){
    cin >> h >> w >> a >> b;
    vvll m(h,vll(w,0));
    dfs(m,a,b,-1);
    cout << ans << endl;
}
