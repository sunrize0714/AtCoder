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
    ll k;
    cin >> k;
    set<ll> mo;
    ll pos = 7;
    ll cnt = 1;
    while(true){
        if(pos % k == 0){
            cout << cnt << endl;
            return 0;
        }
        else{
            pos %= k;
            mo.insert(pos);
            if(mo.size() != cnt){
                cout << -1 << endl;
                return 0;
            }
            else{
                cnt++;
                pos *= 10;
                pos += 7;
            }
        }
    }
}