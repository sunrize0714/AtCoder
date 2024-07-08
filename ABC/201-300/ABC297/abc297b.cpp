#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int b[3],k,r[3],bnow=0,rnow=0;
    for(int i=1;i<9;i++){
        if(s[i-1]=='B'){
            b[bnow]=i;
            bnow++;
        }
        if(s[i-1]=='R'){
            r[rnow]=i;
            rnow++;
        }
        if(s[i-1]=='K')k=i;
    }

    if((b[1]-b[0])%2 == 1  && r[0] < k && r[1] > k){
        cout <<"Yes";
        return 0; 
    }
    cout << "No";
}