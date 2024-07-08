#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin >> n >> d;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    vector<bool> ans(d,true);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            if(s[i][j] == 'x')ans[j] = false;
        }
    }
    int days=0,max_days=0;
    for(int i=0;i<d;i++){
        if(ans[i] == true){
            days++;
            max_days = max(days,max_days);
        }
        else{
            days = 0;
        }
    }
    cout << max_days;
}