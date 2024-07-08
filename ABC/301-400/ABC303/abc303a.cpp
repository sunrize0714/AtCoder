#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;
    for(int i=0;i<n;i++){
        int flag=0;
        if(s[i] != t[i]){
            if(s[i] == '0' && t[i] =='o')flag=1;
            if(s[i] == 'o' && t[i] =='0')flag=1;
            if(s[i] == '1' && t[i] =='l')flag=1;
            if(s[i] == 'l' && t[i] =='1')flag=1;
            if(flag == 0){
            cout << "No";
            return 0;
            }
        }
    }
    cout << "Yes";
}