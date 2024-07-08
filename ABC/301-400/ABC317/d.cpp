#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long int> x(n),y(n),z(n);
    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    long long int seets = 0;
    for(int i=0;i<n;i++)seets += z[i];

    vector<long long int> change(n,0);
    for(int i=0;i<n;i++){
        if(x[i] < y[i]){
            change[i] = (x[i]+ y[i] + 1)/2 - x[i];
        }
    }

    vector<long long int> dp(seets+1,100000000000000);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(long long int j=seets;j>=z[i];j--){
            dp[j] = min(dp[j], dp[j-z[i]] + change[i]);        
        }
    }

    long long int ans = 100000000000000;
    for(long long int i=seets;i>=(seets+1)/2;i--){
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}