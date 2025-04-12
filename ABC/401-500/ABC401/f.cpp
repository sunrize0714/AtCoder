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


/* Rerooting: 全方位木 DP
    問題ごとに以下を書き換える
    - 型DPと単位元
    - 型DPに対する二項演算 merge
    - まとめたDPを用いて新たな部分木のDPを計算する add_root
    計算量: O(N)
*/
struct Rerooting {
    /* start 問題ごとに書き換え */
    struct DP {  // DP の型
        long long dp;
        DP(long long dp_) : dp(dp_) {}
    };
    const DP identity = DP(-1);  // 単位元(末端の値は add_root(identity) になるので注意)
    function<DP(DP, DP)> merge = [](DP dp_cum, DP d) -> DP {
        return DP(max(dp_cum.dp, d.dp));
    };
    function<DP(DP)> add_root = [](DP d) -> DP {
        return DP(d.dp + 1);
    };
    /* end 問題ごとに書き換え */
    // グラフの定義
    struct Edge {
        int to;
    };
    using Graph = vector<vector<Edge>>;
    vector<vector<DP>> dp;  // dp[v][i]: vから出るi番目の有向辺に対応する部分木のDP
    vector<DP> ans;         // ans[v]: 頂点vを根とする木の答え
    Graph G;
    Rerooting(int N) : G(N) {
        dp.resize(N);
        ans.assign(N, identity);
    }
    void add_edge(int a, int b) {
        G[a].push_back({b});
    }
    void build() {
        dfs(0);            // 普通に木DP
        bfs(0, identity);  // 残りの部分木に対応するDPを計算
    }
    DP dfs(int v, int p = -1) {  // 頂点v, 親p
        DP dp_cum = identity;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, identity);
        for (int i = 0; i < deg; i++) {
            int u = G[v][i].to;
            if (u == p) continue;
            dp[v][i] = dfs(u, v);
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void bfs(int v, const DP& dp_p, int p = -1) {  // bfs だが、実装が楽なので中身は dfs になっている
        int deg = G[v].size();
        for (int i = 0; i < deg; i++) {  // 前のbfsで計算した有向辺に対応する部分木のDPを保存
            if (G[v][i].to == p) dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, identity), dp_r(deg + 1, identity);  // 累積merge
        for (int i = 0; i < deg; i++) {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--) {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }
        ans[v] = add_root(dp_l[deg]);  // 頂点 v の答え
        for (int i = 0; i < deg; i++) {  // 一つ隣の頂点に対しても同様に計算
            int u = G[v][i].to;
            if (u == p) continue;
            bfs(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};

int main(){
    int n1,n2;
    cin >> n1;
    Rerooting reroot(n1);
    rep(i,0,n1-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        reroot.add_edge(u,v);
        reroot.add_edge(v,u);
    }
    reroot.build();

    cin >> n2;
    Rerooting reroot2(n2);
    rep(i,0,n2-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        reroot2.add_edge(u,v);
        reroot2.add_edge(v,u);
    }
    reroot2.build();
    ll ans = 0;
    vll v1,v2;
    rep(i,0,n1)v1.push_back(reroot.ans[i].dp);
    rep(i,0,n2)v2.push_back(reroot2.ans[i].dp);
    sort(all(v1)),sort(all(v2));
    ll maxi1 = 0,maxi2 = 0;
    maxi1 = max(maxi1,v1.back());
    maxi2 = max(maxi2,v2.back());
    ll maxi = max(maxi1,maxi2);
    vll wa(n1+1,0);
    rep(i,0,n1)wa[i+1] = wa[i] + v1[i];  
    rep(i,0,n2){
        ll itr = upper_bound(all(v1),maxi-1-v2[i]) - v1.begin();
        ans += maxi*itr + (n1-itr)*(v2[i]+1) + wa[n1] - wa[itr];
    }
    cout << ans << endl;
}
