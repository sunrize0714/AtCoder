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

bool cross(ll a,ll b,ll l,ll r){
    return not (b <= l or r <= a);
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    vll h(3),w(3);
    vector<vs> p(3);
    rep(i,0,3){
        cin >> h[i] >> w[i];
        p[i].resize(h[i]);
        rep(j,0,h[i])cin >> p[i][j];
    }
    bool ans = false;
    string pp;
    rep(i,0,50)pp += '.';
    vs board(50,pp);
    rep(i,0,h[0])rep(j,0,w[0]){
        board[i+20][j+20] = p[0][i][j];
    }
    set<pair<ll,ll>> st;
    ll dx = -1,dy = -1;
    rep(i,0,h[2]){
        rep(j,0,w[2]){
            if(p[2][i][j] == '#'){
                if(dx == -1)dx = i,dy = j;
                st.insert({i-dx,j-dy});
            }
        }
    }
    rep(i,0,50-h[1]){
        rep(j,0,50-w[1]){
            vs x = board;
            rep(ii,0,h[1]){
                rep(jj,0,w[1]){
                    if(p[1][ii][jj] == '#')x[i+ii][j+jj] = '#';
                }
            }
            set<pair<ll,ll>> st2;
            ll dx2 = -1,dy2 = -1;
            rep(ii,0,50){
                rep(jj,0,50){
                    if(x[ii][jj] == '#'){
                        if(dx2 == -1)dx2 = ii,dy2 = jj;
                        st2.insert({ii-dx2,jj-dy2});
                    }
                }
            }
            if(st == st2)ans = true;
        }
    }
    ans ? cout << "Yes" : cout << "No";
}
