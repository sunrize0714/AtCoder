#include<bits/stdc++.h>
using namespace std;
vector<int> g[2001];
bool virus[2001];
vector<int> x[2001],y[2001];

void dfs(int pos){
    virus[pos] = true;
    for(int i=0;i<g[pos].size();i++){
        int nex = g[pos][i];
        if(virus[nex] == false){
            dfs(nex);
        }
    } 
}

int main(){
    long long int n,d;
    cin >> n >> d;
    d = d*d;
    vector<long long int> x(n+1);
    vector<long long int> y(n+1);
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            long long int disx = x[i] - x[j];
            long long int disy = y[i] - y[j];
            if(d>=disx*disx + disy*disy){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i=1;i<=n;i++)virus[i] = false;

    dfs(1);
    for(int i=1;i<=n;i++){
        if(virus[i] == true)cout << "Yes" << endl;
        else cout <<"No"<< endl;
    }
}