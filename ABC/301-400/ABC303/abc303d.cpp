#include<bits/stdc++.h>
using namespace std;
long long int ans[400000][2];

int main(){
    long long int x,y,z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    long long int len = s.size();
    ans[0][0]=0;
    ans[0][1]=z;
    for(long long int i=1;i<=len;i++){
        if(s[i-1] == 'a'){
            ans[i][0]=min(ans[i-1][0] + x, ans[i-1][1] + z + x);
            ans[i][1]=min(ans[i-1][0] + z + y, ans[i-1][1] + y);
        }
        if(s[i-1] == 'A'){
            ans[i][0] = min(ans[i-1][0] + y,ans[i-1][1] + z + y);
            ans[i][1] = min(ans[i-1][0] + z + x, ans[i-1][1] + x);
        }
    }
    cout << min(ans[len][0],ans[len][1]);
}