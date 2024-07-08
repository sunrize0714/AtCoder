#include<bits/stdc++.h>
using namespace std;
int h,w,ans=0;
string s[110];
int a[110];
int main(){
    cin >> h >> w;
    for(int i=0;i<h;i++){
        cin >> s[i];
        for(int j=0;j<w;j++){
            if(s[i][j]=='T' && s[i][j+1]=='T'){
                s[i][j] = 'P';
                s[i][j+1] = 'C';
                j++;
            }
        }
        cout << s[i] << endl;
    }
    
}