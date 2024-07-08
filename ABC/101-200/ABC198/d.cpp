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
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    reverse(all(s1));
    reverse(all(s2));
    reverse(all(s3));
    vector<char> s;
    rep(i,0,s1.size())s.push_back(s1[i]);
    rep(i,0,s2.size())s.push_back(s2[i]);
    rep(i,0,s3.size())s.push_back(s3[i]);
    sort(all(s));
    s.erase(unique(all(s)),s.end());
    vll x(10);
    rep(i,0,10)x[i] = i;
    if(s.size() > 10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    do{
        bool ok = true;
        vll idx(s.size());
        rep(i,0,s.size()){
            idx[i] = x[i];
        }
        ll a1=0,a2=0,a3=0;
        ll pos = 1;
        rep(i,0,s1.size()){
            char j = s1[i];
            ll to = lower_bound(all(s),j) - s.begin();
            a1 += pos*idx[to];
            pos *= 10;
            if(i == s1.size()-1 && idx[to] == 0)ok = false;
        }
        pos = 1;
        rep(i,0,s2.size()){
            char j = s2[i];
            ll to = lower_bound(all(s),j) - s.begin();
            a2 += pos*idx[to];
            pos *= 10;
            if(i == s2.size()-1 && idx[to] == 0)ok = false;
        }
        pos = 1;
        rep(i,0,s3.size()){
            char j = s3[i];
            ll to = lower_bound(all(s),j) - s.begin();
            a3 += pos*idx[to];
            pos *= 10;
            if(i == s3.size()-1 && idx[to] == 0)ok = false;
        }
        if(a1 + a2 == a3 && ok){
            cout << a1 << endl << a2 << endl << a3 << endl;
            return 0;
        }

    }while(next_permutation(all(x)));
    cout << "UNSOLVABLE" << endl;
}