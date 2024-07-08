#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;
typedef string str;

int main(){
    ll n,m,p;
    cin >> n >> m >> p;
    vll a(n),b(m);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vll sumb(m+1);
    sumb[0] = 0;
    for(int i=1;i<=m;i++){
        sumb[i] = sumb[i-1] + b[i-1];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll minimum = p - a[i];
        long long int mini = lower_bound(b.begin(),b.end(),minimum) - b.begin();
        ans += (m-mini)*p;
        ans += mini*a[i];
        ans += sumb[mini];
    }
    cout << ans << endl;
}