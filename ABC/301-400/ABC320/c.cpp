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

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll m;
    cin >> m;
    string s[3];
    rep(i,0,3)cin >> s[i];
    ll array[3]={0,1,2};
    ll ans = 301;
    do{
        //cout << array[0] << array[1] << array[2]<<endl;
        rep(i,0,10){
            ll cnt = 0;
            char to = '0' + i;
            rep(j,1,400){
                if(s[array[cnt]][j%m] == to)cnt++;
                if(cnt == 3){
                    ans = min(ans,j);
                    break;
                }
            }
        }

    }while(next_permutation(array,array+3));
    ans == 301 ? cout << -1 << endl : cout << ans << endl;
}