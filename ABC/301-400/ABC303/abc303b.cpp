#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans=0;
    cin >> n >> m;
    int a[101][101];
    int naka[101][101];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            naka[i][j]=-1;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n-1;j++){
            int now=a[i][j],nex=a[i][j+1];
            naka[now][nex] = 1;
            naka[nex][now] = 1;
        }
    }

    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(naka[i][j] == -1)ans++;
        }
    }
    cout << ans;
}

