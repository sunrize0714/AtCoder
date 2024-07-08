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
    string s;
    ll k;
    cin >> s >> k;
    set<string> st;
    rep(i,0,s.size()){
        rep(j,i,s.size()){
            if(st.size() < k){
                string t = s.substr(i,j-i+1);
                st.insert(t);
            }
            else{
                auto itr = st.begin();
                rep(p,0,k-1)itr++;
                string t = s.substr(i,j-i+1);
                if(*itr > t){
                    st.insert(t);
                }
                else break;
            }
        }
    }
    auto itr2 = st.begin();
    rep(i,0,k-1)itr2++;
    cout << *itr2 << endl;
}