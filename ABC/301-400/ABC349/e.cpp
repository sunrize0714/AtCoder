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

ll a[3][3];
ll use[3][3];
ll check[3][3];
ll point = 0;
bool ans = false;
void dfs(ll ai,ll bi,ll cnt){
    use[ai][bi] = cnt%2;
    if(cnt == 8){
        rep(i,0,3)rep(j,0,3){
            if(use[i][j] == 0)point += a[i][j];
            else point -= a[i][j];
        }
        if(point > 0){
            ans = true;
        }
        point = 0;
    }
    else{
        rep(i,0,3){
            rep(j,0,3){
                if(use[i][j] == -1){
                    rep(i2,0,3){
                        rep(j2,0,3){
                            check[i2][j2] = a[i2][j2];
                        }
                    }
                    check[i][j] = cnt%2;
                    bool ng = false;
                    rep(i2,0,3){
                        if(check[i2][0] == check[i2][1] && check[i2][1] == check[i2][2] && check[i2][0] != -1)ng = true;
                    }
                    rep(i2,0,3){
                        if(check[0][i2] == check[1][i2] && check[1][i2] == check[2][i2] && check[0][i2] != -1)ng = true;
                    }
                    if(check[0][0] == check[1][1] && check[1][1] == check[2][2] && check[0][0] != -1)ng = true;
                    if(check[0][2] == check[1][1] && check[1][1] == check[2][0] && check[0][2] != -1)ng = true;
                    if(!ng)dfs(i,j,cnt+1);
                }
            }
        }
    }
    use[ai][bi] = -1;
}
int main(){
    rep(i,0,3)rep(j,0,3)cin >> a[i][j];
    rep(i,0,3)rep(j,0,3)use[i][j] = -1;
    rep(i,0,3){
        rep(j,0,3){
            dfs(i,j,0);
        }
    }
    if(ans){
        cout << "Takahashi";
        return 0;
    }
    cout << "Aoki" << endl;
}