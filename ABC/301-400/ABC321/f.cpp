#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;

int main(){
    ll q,k;
    cin >> q >> k;
    vll dp(k+1,0);
    dp[0] = 1;
    for(int i=0;i<q;i++){
        string s;
        ll x;
        cin >> s >> x;
        if(s == "+"){
            for(int j=k;j>=x;j--){
                dp[j] += dp[j-x];
                dp[j] %= 998244353;
            }
        }
        else{
            for(int j=x;j<=k;j++){
                dp[j] += (998244353 - dp[j-x]);
                dp[j] %= 998244353;
            }
        }
        cout << dp[k]%998244353 << endl;
    }
}