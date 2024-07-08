#include<bits/stdc++.h>
using namespace std;
long long int sa[100000];
int main(){
    long long int a,b,ans=0;
    cin >> a >> b;
    while(true){
    if(a==b){
        cout << ans;
        return 0;
    }
    if(a<b)swap(a,b);

    if((a-b)%b != 0){
        ans += (a-b)/b+1;
        a -= b*((a-b)/b)+b;
        //cout << a << " " << b <<" " << ans<< endl;
        if(a<b)swap(a,b);
    }
    if((a-b)%b==0){
        cout << ans + (a-b)/b;
        return 0;
    }
    }
}