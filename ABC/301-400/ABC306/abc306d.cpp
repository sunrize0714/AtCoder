#include<bits/stdc++.h>
using namespace std;
long long int dp[2][4000000];
int main(){
    int n;
    cin >> n;
    vector<long long int> x(n+1),y(n+1);
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=1;j++)dp[j][i] = 0;
    }
    //vector<vector<long long int>> dp(n+1,vector<long long int>(2,0));
    for(int i=1;i<=n;i++){
        if(x[i] == 0) dp[0][i] = max({dp[0][i-1]+y[i],dp[1][i-1]+y[i],dp[0][i-1]});
        else dp[0][i] = dp[0][i-1];

        if(x[i] == 1) dp[1][i] = max(dp[0][i-1]+y[i],dp[1][i-1]);
        else dp[1][i] = dp[1][i-1]; 
    }

    cout << max(dp[0][n],dp[1][n]);
}                                                   