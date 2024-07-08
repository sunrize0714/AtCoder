#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.size() == 1){
        cout << s << endl;
        return 0;
    }
    long long int ans = 0;
    vector<vector<char>> dp(n+1,vector<char>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = s[j];
            if(i==j)ans++;
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(dp[i][j] == dp[i][j+1]){
                dp[i][j+1] = '1';
                ans++;
            }
            else{
                dp[i][j+1] = '0';
            } 
        }
    }
    cout << ans;
}