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
    vll v(3);
    rep(i,0,3)cin >> v[i];
    if(v[0] + v[1]*2 + v[2]*3 != 1029){
        cout << "No" << endl;
        return 0;
    }
    vll a(3),b(3),c(3);
    a[0] = 0,b[0] = 0,c[0] = 0;
    bool f = false;
    rep(i,-7,8){
        rep(j,-7,8){
            rep(k,-7,8){
                rep(l,-1,8){
                    rep(m,-1,8){
                        rep(n,-1,8){
                            ll three,two=0;
                            ll x1 = max({0LL,i,l});
                            ll x2 = min({7LL,i+7,l+7});
                            ll y1 = max({0LL,j,m}), y2 = min({7LL,j+7,m+7});
                            ll z1 = max({0LL,k,n}), z2 = min({7LL,k+7,n+7});
                            three = max((x2-x1),0LL)*max((y2-y1),0LL)*max((z2-z1),0LL);
                            if(three != v[2])continue;
                            two += max((7-i),0LL)*max((7-j),0LL)*max((7-k),0LL);
                            two += max((7-l),0LL)*max((7-m),0LL)*max((7-n),0LL);
                            ll xx,yy,zz;
                            xx = max(min(i+7,l+7)-max(i,l),0LL);
                            yy = max(min(j+7,m+7)-max(j,m),0LL);
                            zz = max(min(k+7,n+7)-max(k,n),0LL);
                            two += xx*yy*zz;
                            two -= v[2]*3;
                            if(two == v[1]){
                                f = true;
                                a[1] = i,b[1] = j,c[1] = k,a[2] = l,b[2] = m,c[2] = n;
                                break;
                            }
                        }
                        if(f)break;
                    }
                    if(f)break;
                }
                if(f)break;
            }
            if(f)break;
        }
        if(f)break;
    }
    map<ll,ll> ok;
    rep(i,0,8)rep(j,0,8)rep(k,0,8)ok[i*j*k] = 1;
    if(!f && v[2] == 0){
        if(ok[v[1]] == 1){
            rep(i,0,8)rep(j,0,8)rep(k,0,8){
                if(i*j*k == v[1]){
                    a[1] = 7-i,b[1] = 7-j,c[1] = 7-k;
                    a[2] = 50,b[2] = 50,c[2] = 50;
                    f = true;
                    break;
                } 
            }
        }
        else{
            rep(i,1,v[1]){
                if(ok[i] == 1 && ok[v[1]-i] == 1){
                    rep(j,0,8)rep(k,0,8)rep(l,0,8){
                        if(j*k*l == i){
                            rep(m,0,8)rep(n,0,8)rep(p,0,8){
                                if(m*n*p == v[1]-i){
                                    vll x = {j,k,l};
                                    vll y = {m,n,p};
                                    sort(all(x)),sort(all(y));
                                    reverse(all(y));
                                    if(x[0]+y[0] <= 7 && x[1]+y[1] <= 7 && x[2]+y[2] <= 7){
                                        a[1] = 7-x[0],b[1] = 7-x[1],c[1] = 7-x[2];
                                        a[2] = y[0]-7,b[2] = y[1]-7,c[2] = y[2]-7;
                                        f = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(!f && v[1] == 0){
        if(ok[v[2]] == 1){
            rep(i,0,8)rep(j,0,8)rep(k,0,8){
                if(i*j*k == v[2]){
                    a[1] = 7-i,b[1] = 7-j,c[1] = 7-k;
                    a[2] = 7-i,b[2] = 7-j,c[2] = 7-k;
                    f = true;
                    break;
                } 
            }
        }
    }
    if(f){
        cout << "Yes" << endl;
        rep(i,0,3)cout << a[i] << " " << b[i] << " " << c[i] << " ";
        cout << endl;
        return 0;
    }
    else cout << "No" << endl;
}