#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int start =100000000;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(start > a[i])start = a[i];
    }

    sort(a.begin(),a.end());
    for(int i=1;i<=n+1;i++){
        if(a[i] != i + start){
            cout << i+start << endl;
            return 0;
        }
    }
    
}