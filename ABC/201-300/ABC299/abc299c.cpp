#include<bits/stdc++.h>
using namespace std;

int n,ans,bou[400000],wa[400000];
string s;
int main(){
    cin >> n >> s;
    int bar = 0; 
    for(int i=0;i<n;i++){
      if(s[i]=='-'){
        bou[bar] = i;
        bar++;
      }
    }

    if(bar == 0 || bar == n)cout << "-1";
    else{
        wa[0]=bou[0];
        for(int i=0;i<bar-1;i++){
            wa[i+1] = bou[i+1] - bou[i] -1;
        }
        wa[bar] = n-bou[bar-1];
        ans=0;
        for(int i=0;i<=bar;i++){
          if(ans < wa[i]){
            ans = wa[i];
          }
        }
        cout << ans;
    }

    
}