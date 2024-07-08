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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

int main(){
    ll n;
    string s,t;
    cin >> n >> s >> t;
    string ss = s,tt = t;
    if(s == t){
        cout<< 0 << endl;
        return 0;
    }
    sort(all(ss)),sort(all(tt));
    if(ss != tt){
        cout << -1 << endl;
    }
    else{
        string a = s + ".."; 
        map<string,ll> dist;
        queue<string> q;
        q.push(a);
        while(!q.empty()){
            string pos = q.front();q.pop();
            if(pos == t + ".."){
                cout << dist[pos];
                return 0;
            }
            ll aki;
            rep(i,0,n+1){
                if(pos[i] == pos[i+1] && pos[i] == '.')aki = i;
            }
            rep(i,0,n+1){
                if(i != aki && i+1 != aki && i != aki+1){
                    string x = pos.substr(i,2);
                    string to = pos;
                    to[aki] = x[0],to[aki+1] = x[1];
                    to[i] = to[i+1] = '.';
                    if(dist[to] == 0 && to != a){
                        dist[to] = dist[pos]+1;
                        q.push(to);
                    }
                } 
            }
        }
        cout << -1;
    }
}