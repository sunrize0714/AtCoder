#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    vector<char> b(n*n);
    for(int i=0;i<n*n;i++){
        cin >> b[i];
    }

    for(int i=n-1;i>0;i--){
        swap(b[i],b[i-1]);
    }
    for(int i=0;i<=n*n-n-n;i+=n){
        swap(b[i],b[i+n]);
    }
    for(int i=n*n-n;i<n*n-1;i++){
        swap(b[i],b[i+1]);
    }
    for(int i=n*n-1;i>=n-1;i-=n){
        swap(b[i],b[i-n]);
    }

    for(int i=0;i<n*n;i++){
        cout << b[i] ;
        if((i+1) % n == 0)cout << endl;
    }
}