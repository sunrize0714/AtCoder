#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k;cin >> n >> k;
    vector<pair<long long int,long long int>> a(n);
    long long int start=0;
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
        start += a[i].second;
    }

    sort(a.begin(),a.end());


    if(start <= k){
        cout << 1 << endl;
        return 0;
    }

    for(long long int i=0;i<n;i++){
        start -= a[i].second;
        if(start <= k){
            cout << a[i].first+1 << endl;
            return 0;
        }
    }
}