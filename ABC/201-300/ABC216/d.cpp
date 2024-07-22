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
    ll n,m;
    cin >> n >> m;
    vll k(m);
    vvll a(m);
    rep(i,0,m){
        cin >> k[i];
        rep(j,0,k[i]){
            ll x;
            cin >> x;
            a[i].push_back(x);
        }
        reverse(all(a[i]));
    }
    vvll state(n+1);
    rep(i,0,m){
        rep(j,0,k[i])state[a[i][j]].push_back(i);
    }
    queue<ll> q;
    set<ll> st;
    rep(i,0,m){
        if(a[i].size() == 0)continue;
        ll pos = a[i].back();
        if(st.count(pos) == 0)st.insert(pos);
        else{
            st.erase(pos);
            q.push(pos);
        }
    }
    ll cnt = 0;
    while(!q.empty()){
        ll pos = q.front();q.pop();
        cnt++;
        rep(i,0,2){
            ll to = state[pos][i];
            a[to].pop_back();
            if(a[to].size() != 0){
                ll pos2 = a[to].back();
                if(st.count(pos2) == 0)st.insert(pos2);
                else{
                    st.erase(pos2);
                    q.push(pos2);
                }
            }
        }
    }
    if(cnt == n)cout << "Yes";
    else cout << "No";
}
