#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(3*n+1),ans(n+1),counts(n+1);
    for(int i=1;i<=3*n;i++){
        cin >> a[i];
        counts[a[i]]++;
        if(counts[a[i]] == 2)ans[a[i]] = i;
    }
    pair<int,int> index[100000];
    for(int i=1;i<=n;i++){
        index[i].first=ans[i];
        index[i].second=i;
    }
    sort(index+1,index+n+1);
    for(int i=1;i<=n;i++){
        cout << index[i].second << " ";
    }

}