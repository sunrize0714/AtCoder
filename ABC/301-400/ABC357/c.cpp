#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll n;

void dfs(vs s,ll N){
    if(N == n){
        rep(i,0,s.size()){
            cout << s[i] << endl;
        }
        cout << endl;
        return;
    }
    else{
        ll cnt = s.size();
        vs x(3*cnt);
        rep(i,0,cnt){
            x[i]+=s[i];
            x[i]+=s[i];
            x[i]+=s[i];
        }
        rep(i,0,cnt){
            x[cnt+i]+=s[i];
            rep(j,0,cnt)x[cnt+i]+=".";
            x[cnt+i]+=s[i];
        }
        rep(i,0,cnt){
            x[cnt*2+i]+=s[i];
            x[cnt*2+i]+=s[i];
            x[cnt*2+i]+=s[i];
        }
        dfs(x,N+1);
    }
}

int main(){
    cin >> n;
    if(n == 0)cout << "#";
    else{
    vs p(1);
    string z;
    z += "#";
    p[0] += z;  
        dfs(p,0);
        
    }
}