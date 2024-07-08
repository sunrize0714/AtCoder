#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int start =100000000;
    vector<int> a(n),b(n),c(n),d(n);
    vector<vector<int>> seet(1010,vector<int>(1010,0));
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    for(int i=0;i<n;i++){
        seet[a[i]][c[i]]++;
        seet[b[i]][d[i]]++;
        seet[a[i]][d[i]]--;
        seet[b[i]][c[i]]--;
    }

    for(int i=0;i<101;i++){
        for(int j=0;j<100;j++){
            seet[i][j+1] += seet[i][j];
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<101;j++){
            seet[i+1][j] += seet[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(seet[i][j] != 0)ans++;
        }
    }
    cout << ans;
}