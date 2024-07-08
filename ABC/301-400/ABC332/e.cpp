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
    double n,d;
    cin >> n >> d;
    vector<double> w(n);
    rep(i,0,n)cin >> w[i];
    sort(w.begin(),w.end(),greater());
    double ans = 1e18;
    double xbar = 0.0;
    rep(i,0,n)xbar += w[i];
    if(d == n){
        ans = 0.0;
        double bar = xbar/n;
        rep(i,0,n){
            ans += (bar - w[i])*(bar -w[i]);
        }
        cout << setprecision(15) << ans << endl;
    }
    else{
        vector<double> box(((ll)d),0.0);
        vll in(n);
        rep(i,0,n){
            in[i] = i%((ll)d);
        }
        rep(i,0,n){
            box[in[i]] += w[i];
        }
        double bar = xbar/d;
        //cout << bar << endl;

        while(true){
            double pos_ans = 0.0;
            rep(i,0,d){
                pos_ans += (bar - box[i])*(bar - box[i]);
            }

            rep(i,0,n){
                rep(j,0,d){
                    double now = abs(box[in[i]]-bar) + abs(box[j]-bar);
                    if(abs(box[in[i]]-bar-w[i]) + abs(box[j]-bar+w[i]) < now){
                        box[in[i]] -= w[i];
                        box[in[i]] = j;
                        box[j] += w[i];
                    }
                }
            }

            rep(i,0,n-1){
                rep(j,i+1,n){
                    ll pos1 = in[i],pos2 = in[j];
                    double now = abs(box[pos1]-bar) + abs(box[pos2]-bar);
                    if(pos1 == pos2)continue;
                    if(abs(box[pos1]-w[i]+w[j]-bar)+abs(box[pos2]-w[j]+w[i]-bar) < now){
                        box[pos1] -= w[i];
                        box[pos2] -= w[j];
                        swap(in[i],in[j]);
                        box[in[i]] += w[i];
                        box[in[j]] += w[j]; 
                    }
                }
            }

            

            double after_ans = 0.0;
            rep(i,0,d){
                after_ans += (bar - box[i])*(bar - box[i]);
            }
            if(after_ans >= pos_ans){
                cout << setprecision(15) << pos_ans/d << endl;
                return 0;
            }
        }
    }
}