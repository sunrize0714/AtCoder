#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll n;
string r,c;

void dfs(ll cnt,vector<string> & a){
    //全行が適合したら列のチェック
    if(cnt == n){
        bool ok = true;
        rep(i,0,n){
            bool f = true;
            vll abc(3,0);
            rep(j,0,n){
                if(a[j][i] == '.')continue;
                //先頭が違反したら即終わり
                if(a[j][i] != '.' && abc[0] == 0 && abc[1] == 0 && abc[2] == 0 && a[j][i] != c[i]){
                    ok = false;
                    f = false;
                    break;
                }
                //各文字が一列に一回ずつ出てくるか確認
                if(a[j][i] != '.'){
                    ll to = a[j][i] - 'A';
                    abc[to]++;
                    if(!f)break;
                }
            }
            if(abc[0] != 1 || abc[1] != 1 || abc[2] != 1){
                ok = false;
                f = false;
            }
            if(!f)break;
        }
        //適合したら即終了
        if(ok){
            cout << "Yes" << endl;
            rep(i,0,n){
                cout << a[i] << endl;
            }
            return;
        }
    }
    else{
    do{
        bool f2 = true;
        rep(i,0,n){
            if(a[cnt][i] == '.')continue;
            if(a[cnt][i] != r[i]){
                f2 = false;
                break;
            }
            else{
                break;
            }
        }
        rep(j,0,n){
            vll abc2(3,0);
            rep(i,0,cnt+1){
                if(a[i][j] == '.')continue;
                //先頭が違反したら即終わり
                if(a[i][j] != '.' && abc2[0] == 0 && abc2[1] == 0 && abc2[2] == 0 && a[i][j] != c[j]){
                    f2 = false;
                    break;
                }
                if(a[i][j] != '.'){
                    ll to = a[i][j] - 'A';
                    abc2[to]++;
                }
            }
            if(abc2[0] > 1 || abc2[1] > 1 || abc2[2] > 1)f2 = false;
        }
        //条件を満たしていれば次の行を探索
        
        if(f2){
            dfs(cnt+1,a);

        }
    }while(next_permutation(all(a[cnt])));
    }
}

int main(){
    cin >> n;
    cin >> r >> c;
    vector<string> x(n);
    rep(i,0,n){
        x[i] = string(n,'.');
        rep(j,0,3)x[i][j] = 'A' + j;
    }
    rep(i,0,n)sort(all(x[i]));
    dfs(0,x);
    cout << "No" << endl;
}