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

vs goal(4,"####");
bool ans = false;
vector<vs> p(3,vs(4));
void dfs(vs board,ll cnt,vector<vs> p){
    if(cnt == 3){
        if(board == goal)ans = true;
    }
    else{
        rep(i,-4,4){
            rep(j,-4,4){
                bool ok = true;
                vs board2 = board;
                rep(ii,0,4){
                    rep(jj,0,4){
                        if(p[cnt][ii][jj] == '#'){
                            if(in_field(0,4,i+ii) & in_field(0,4,j+jj)){
                                if(board[i+ii][j+jj] == '.'){
                                    board2[i+ii][j+jj] = '#';
                                }
                                else{
                                    ok = false;
                                }
                            }
                            else{
                                ok = false;
                            }
                        }
                    }
                }
                if(ok)dfs(board2,cnt+1,p);
            }
        }
    }
}

vs rotation(vs s){
    vs x = s;
    rep(i,0,4){
        rep(j,0,4){
            x[i][3-j] = s[j][i];
        }
    }
    return x;
}
int main(){
    vs b(4,"....");
    rep(i,0,3)rep(j,0,4)cin >> p[i][j];
    rep(i,0,4){
        rep(j,0,4){
            dfs(b,0,p);
            p[1] = rotation(p[1]);
        }
        p[2] = rotation(p[2]);
    }
    if(ans)cout << "Yes";
    else cout << "No";
}
