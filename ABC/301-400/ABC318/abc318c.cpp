#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,d,p;
    cin >> n >> d >> p;
    vector<long long int> f(n);
    for(int i=0;i<n;i++)cin >> f[i];
    sort(f.begin(),f.end());
    for(int i=1;i<n;i++){
        f[i] += f[i-1];
    }
    long long int ans = f[n-1];
    for(long long int i=n-1;i>=0;){
        if(i>=d){
            if(f[i]-f[i-d] > p){
                ans -= f[i]-f[i-d] - p;
            }
        }
        else{
            if(f[i] > p)ans -= f[i]-p;
        }
        i -= d;
    }
    cout << ans;
}