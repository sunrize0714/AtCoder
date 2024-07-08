#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        cout << a[i];
        if(i!=n-1)cout << " ";

        if(a[i] > a[i+1] && a[i]-a[i+1]>1){
            for(int j=a[i]-1;j>a[i+1];i--){
                cout << j << " ";
            }
        }
        else if(a[i] < a[i+1] && a[i+1]-a[i]>1){
            for(int j=a[i]+1;j<a[i+1];j++){
                cout << j << " ";
            }
        }
    }
    cout << a[n-1];
}