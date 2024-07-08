#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int ans = 0,bai=1;
    unsigned long long int a[65];
    for(int i=0;i<65;i++)a[i]=0;
    for(long long int i=0;i<64;i++){
        cin >> a[i];
        ans += a[i] * bai;
        bai*=2;
    }
    cout << ans;
}