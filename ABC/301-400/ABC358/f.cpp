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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    if(k < n || (k-n)%2 == 1){
        cout << "No" << endl;
    }
    else if(m == 1){
        cout << "Yes" << endl;
        cout << "+S+" << endl;
        rep(i,0,n){
            if(i != n-1){
                cout << "+o+" << endl;
                cout << "+.+" << endl;
            }
            else{
                cout << "+o+" << endl;
                cout << "+G+" << endl;
            }
        }
    }
    else{
        cout << "Yes" << endl;
        vs ans(2*n+1);
        string x;
        rep(i,0,2*m-1)x += '+';
        ans[0] = x + "S+";
        ans[2*n] = x + "G+";
        string y;
        y += '+';
        rep(i,1,2*n){
            ans[i] += '+';
            rep(j,0,m){
                if(i % 2 == 1){
                    ans[i] += "o|";
                }
                else ans[i] += "-+";
            }
                if(i%2 == 1){
                    ans[i].pop_back();
                    ans[i] += '+';
                }
            
            if(i%2 == 0)ans[i][2*m-1] = '.';
        }
        ll cnt = k-n;
        cnt /= 2;
        
        ll len = k-n;
        len /= 2;
        rep(i,0,len/(m-1)){
            revrep(j,1,m){
                ans[i*4+1][j*2] = '.';
                ans[i*4+2][j*2+1] = '-';
                ans[i*4+3][j*2] = '.';
            }
            ans[i*4+2][1] = '.';
        }
        if(n%2 == 0){
            ll cntx = 1+ len/(m-1)*4,cnty = m*2-2;
            ll tmp = len%(m-1);
            while(tmp > 0){
                ans[cntx][cnty] = '.';
                ans[cntx+1][cnty-1] = '.';
                ans[cntx+1][cnty+1] = '-';
                ans[cntx+2][cnty] = '.';
                tmp--;
                cnty -= 2;
            }
        }
        if(n%2 == 1 && k > (n-1)*m+1){
            ll p = k-(n-1)*m;
            p--;
            p /= 2;
            ll cntx = n*2-1,cnty = 2*(m-2);
            while(p > 0){
                ans[cntx][cnty] = '.';
                ans[cntx-2][cnty] = '|';
                ans[cntx-1][cnty+1] = '.';
                ans[cntx-1][cnty-1] = '.';
                cnty -= 4;
                p--;
            }
        }
        rep(i,1,2*n){
            rep(j,1,2*m){
                if(ans[i][j] == '+' && (i+j)%2 == 1){
                    if(i%2 == 0)ans[i][j] = '-';
                    else ans[i][j] = '|';
                }
            }
        }
        rep(i,0,2*n+1)cout << ans[i] << endl;
    }
}