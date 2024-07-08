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
    ll n,m,k;
    cin >> n >> m >> k;
    vll u(m),v(m),w(m);
    vvll dist(n,vll(n,1e18));
    vll siz(n,0);
    rep(i,0,m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
        w[i]=k;
        dist[u[i]][v[i]] = w[i];
        siz[u[i]]++;
        siz[v[i]]++;
    }
    
   
    ll must = 0;

    rep(i,0,10){
        rep(j,0,n){
            if(siz[j] == 1){
                rep(k,0,n)
                if(dist[j][k] != 1e18 || dist[k][j] != 1e18){
                    must += min(dist[k][j],dist[j][k]);
                    siz[j]--;
                    siz[k]--;
                    break;
                }
            }
        }
    }
    vll array;
    rep(i,0,n){
        if(siz[i] > 0){
            array.push_back(i);
        }
    }
    ll ans = k;
    if(array.size() == 0){
        ans = must;
        ans %= k;
    }
    if(array.size() > 0){
    do{ 
        vll retu;
        rep(i,0,array.size()){
            retu.push_back(array[i]);
        }
        ll cost = 0;
        rep(i,1,n){
            ll from = retu[i-1];
            ll to = retu[i];
            
            if(from > to)swap(from,to);

            if(dist[from][to] == 1e18){
                cost = 1e18;
                break;
            }
            else{
                cost += dist[from][to];
            }
        }

        if(cost != 1e18){
            cost += must;
            cost %= k;
            ans = min(ans,cost);
        }


        rep(i,0,n){
            cout << array[i] << " ";
        }
        cout << endl;
        cout << cost << endl;
    }while(next_permutation(array.begin(),array.end()));
    }
    cout << ans << endl;
}