#include<bits/stdc++.h>
using namespace std;
string s,t;
char mo[8]={'a','t','c','o','d','e','r','@'};
int mojis[30],mojit[30],sa=0,ta=0;
int main(){
    cin >> s >> t;
    for(int i=0;i<8;i++){
        for(int j=0;j<s.size();j++){
            if(s[j] == mo[i]){mojis[i]++;sa++;}
            if(t[j] == mo[i]){mojit[i]++;ta++;}
        }
    }
    if(sa != ta){
        cout << "No" << endl;
        return 0;
    }
    int all=0,all2=0;
    for(int i=0;i<7;i++){
        if(mojis[i]>mojit[i])all+=(mojis[i]-mojit[i]);
        else all2+=(mojit[i]-mojis[i]);
    }

    if(all>mojit[7] || all2>mojis[7])cout << "No" << endl;
    else cout << "Yes" << endl;
}