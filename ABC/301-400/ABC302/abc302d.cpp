#include<bits/stdc++.h>
using namespace std;
long long int n,m,d,a[210000],b[210000],ans=-1;
int main(){
    cin >> n >> m >> d;

    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<m;i++)cin >> b[i];

    sort(a,a+n,greater<long long int>());
    sort(b,b+m,greater<long long int>());

    for(int i=0;i<n;i++){
        if(ans >2*a[i]+d)break;
        for(int j=0;j<m;j++){
            if(a[i]+b[j]>ans && abs(a[i]-b[j])<=d){
                ans=a[i]+b[j];
                break;
            }
            if(a[i]-b[j]>d)break;
        }
    }
    cout << ans;
}