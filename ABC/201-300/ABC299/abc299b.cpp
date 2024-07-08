#include<bits/stdc++.h>
using namespace std;
long long int n,t,c[10000000],r[10000000],ans = 0,ans_color = 0;
int main(){
  cin >> n >> t;
  int flag=0,max=0;
  for(int i=0;i<n;i++){
    cin >> c[i];
    if(c[i]==t)flag =1;
  }   
   for(int i=0;i<n;i++){
    cin >> r[i];
  }   
  if(flag == 1)
  for(int i=0;i<n;i++){
    if(c[i] == t && max < r[i]){
        max = r[i];
        ans = i+1;
    }
  }
  else{
    ans = 1,max=r[0];
    for(int i=0;i<n;i++){
      if(max < r[i] && c[0] == c[i]){
        max = r[i];
        ans = i+1;
      }
    }
  }
  cout << ans;
}