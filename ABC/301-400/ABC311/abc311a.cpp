#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a=1,b=1,c=1;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++){
        if(s[i] == 'A')a=0;
        if(s[i] == 'B')b=0;
        if(s[i] == 'C')c=0;
        if(a+b+c == 0){
            cout << i+1;
            return 0;
        }
    }
}