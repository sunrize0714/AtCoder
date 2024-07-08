#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> c(n);
    for(int i=0;i<n;i++)cin >> c[i];
    vector<string> d(m+1);
    for(int i=1;i<=m;i++)cin >> d[i];
    int ans = 0;
    vector<int> p(m+1);
    for(int i=0;i<=m;i++)cin >> p[i];
    for(int i=0;i<n;i++){
        int flag = 1;
            for(int k=1;k<=m;k++){
                if(c[i] == d[k]){
                    ans += p[k];
                    flag = 0;
                }
            }
        if(flag == 1)ans += p[0];
    }
    cout << ans << endl;
}
