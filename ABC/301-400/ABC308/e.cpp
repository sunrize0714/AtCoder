#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<long long int> a(3*n);
    for(int i=0;i<3*n;i++)cin >> a[i];
    sort(a.begin(),a.end(),greater<long long int>());
    long long int ans = 0;
    for(int i=0;i<=2*n;i++){
        if(i%2 == 1)ans += a[i];
    }
    cout << ans << endl;
}