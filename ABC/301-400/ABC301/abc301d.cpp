#include<bits/stdc++.h>
using namespace std;
string s;
long long int n,sums=0,hatena[61],bits=1,now=0;
int main(){
    cin >> s;
    cin >> n;
    int len=s.size();
    for(int i=len-1;i>=0;i--){
        if(s[i]=='1')sums+=bits;
        else if(s[i]=='?'){
            hatena[now]=bits;
            now++;
        }
        bits*=2;
    }
    
    if(sums>n){
        cout << "-1";
        return 0;
    }
    for(int i=now-1;i>=0;i--){
        if((n-sums)>=hatena[i])sums+=hatena[i];
    }
    cout << sums;
}