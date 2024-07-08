#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}
 
ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n;
    cin >> n;
    vs s(n);
    rep(i,0,n)cin >> s[i];
    vp p,m;
    rep(i,0,n){
        stack<char> st;
        rep(j,0,s[i].size()){
            if(s[i][j] == '(')st.push('(');
            else{
                if(st.size()!=0){
                    if(st.top() == '(')st.pop();
                    else st.push(')');
                }
                else st.push(')');
            }
        }
        ll op = 0,cl = 0;
        while(!st.empty()){
            if(st.top() == '(')op++;
            else cl++;
            st.pop();
        }
        if(op >= cl)p.push_back(make_pair(cl,op));
        else m.push_back(make_pair(-op,cl));
    }
    sort(all(p)),sort(all(m));
    ll cnt = 0;
    bool ans = true;
    rep(i,0,p.size()){
        cnt -= p[i].first;
        if(cnt < 0)ans = false;
        cnt += p[i].second;
    }
    rep(i,0,m.size()){
        cnt -= m[i].second;
        if(cnt < 0)ans = false;
        cnt -= m[i].first;
    }
    if(cnt != 0)ans = false;
    if(ans)cout << "Yes";
    else cout << "No";
}