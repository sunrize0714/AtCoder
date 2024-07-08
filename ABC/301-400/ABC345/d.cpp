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

ll n,h,w;
ll A[7],B[7];
ll a[7],b[7];
ll idx[7];
bool t[10][10];

bool check(){
    ll pos = 0;
    rep(i,0,h)rep(j,0,w)t[i][j] = false;
    rep(i,0,h)rep(j,0,w){
        if(!t[i][j]){
            if(pos == n)return false;
            rep(x,0,a[pos]){
                rep(y,0,b[pos]){
                    ll tx = i+x,ty = j+y;
                    if(tx >= h || ty >= w || t[tx][ty])return false;
                    t[tx][ty] = true;
                }
            }
        }
        pos++;
    }
    return true;
}

int main(){
    cin >> n >> h >> w;
    rep(i,0,n)cin >> A[i] >> B[i];
    rep(i,0,n)idx[i] = i;
    do{
        rep(i,0,1<<n){
            rep(j,0,n){
                a[i] = A[idx[i]];
                b[i] = B[idx[i]];
                if(i&1<<j)swap(a[i],b[i]);
            }
            if(check()){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }while(next_permutation(idx,idx+n));
    cout << "No" << endl;
}