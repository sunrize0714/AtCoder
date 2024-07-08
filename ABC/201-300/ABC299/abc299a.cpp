#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n;
    cin  >> n >> s;
    int count=0;
    int ans = 0;
    int a[10];
    for(int i=0;i<n;i++){
        if(s[i]=='|'){ a[count]=i; count++;}
        if(s[i]=='*')ans = i;
    }
    if((a[0]-ans)*(a[1]-ans)<0)
    cout << "in" << endl;
    else cout <<"out" << endl;
}