#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.size();
    if(len<4)cout << s;
    else{
        for(int i=0;i<3;i++){
            cout << s[i];
        }
        for(int i=3;i<len;i++)
        cout << "0";
    }
}