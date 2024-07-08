#include<bits/stdc++.h>
using namespace std;
int main(){                      
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    vector<int> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t.push_back(a[i][j]);
        }
    }
    sort(t.begin(),t.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j] = lower_bound(t.begin(),t.end(),a[i][j]) - t.begin();
            a[i][j]++;
        }
    }

    int ans=0;
    for(int i=1;i<n;i++){
       for(int j=i+1;j<=n;j++){
        set<int> s;
            for(int k=1;k<=m;k++){
                s.insert(a[i][k]);
                s.insert(a[j][k]);
            }
            for(int k=1;k<=m;k++){
                int ichi = *s.lower_bound(a[i][k]);
                ans += ichi;
            }
       }
    } 
    cout << ans;
}