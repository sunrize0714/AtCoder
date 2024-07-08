#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,p,q;
    cin >> n >> p >> q;
    vector<int> d(n+1);
    int ans = p;
    for(int i=0;i<n;i++){
        cin >> d[i];
        ans = min(ans,q+d[i]);

    }
    cout << ans ;
}