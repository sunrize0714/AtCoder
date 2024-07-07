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

int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    ans += (n-k)*(k-1)*6;
    ans += (n-1)*3;
    ans += 1;
    double a = double(ans)/double(n);
    a = a/double(n);
    a = a/double(n);
    printf("%.10f\n",a);
}