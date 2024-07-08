#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;
typedef string str;

int main(){
    ll n,x;
    cin >> n >> x;
    vll a(n-1);
    for(int i=0;i<n-1;i++)cin >> a[i];
    for(int i=0;i<=100;i++){
        vll b(n);
        for(int j=0;j<n-1;j++)b[i] = a[i];
        b.push_back(i);
        sort(b.begin(),b.end());
        ll ans = 0;
        for(int j=1;j<n-1;j++){
            ans += b[i];
        }
        if(ans > x){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}