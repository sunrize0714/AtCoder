#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;
typedef string str;

int main(){
    ll t;
    cin >> t; 
    for(int i=0;i<t;i++){
        ll n,x,k;
        cin >> n >> x >> k;
        if(k == 0 || k > 120)cout << 1 << endl;
        else{
            ll now_upper = x,now_lower = x,upper_points= 1,lower_points=1;
            
            for(int j=0;j<=k;j++){
                if(now_lower*2 < n)now_lower *= 2;
                now_lower++;
                now_upper /= 2;
                now_lower*=2;
                if(now_lower>n)now_lower = 2*now_lower-n;
            }
        }
    }
}