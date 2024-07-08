#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag=0;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            cout << "No";
        }
        if(s[i]=='o'){
            flag=1;
        }
    }
    if(flag==1)cout << "Yes";
    else cout << "No";
}