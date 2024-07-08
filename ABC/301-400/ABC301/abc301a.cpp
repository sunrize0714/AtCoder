#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0,flag=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
      if(s[i]=='T')a++;
    }
    if(n==1){
        cout >> s << endl;
        return 0;
    }
    if(a<n/2)flag=1;
    if(a==n/2){
        if(s[n-1]=='T')flag=1;
    }
    if(flag==1)cout << 'A' << endl;
    else cout << 'T' << endl;
}