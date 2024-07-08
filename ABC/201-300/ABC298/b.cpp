#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,flag=1;
    int a[110][110],b[110][110],c[110][110];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin >> a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        cin >> b[i][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(a[i][j] == 1 && a[i][j]!=b[i][j]){
            flag=0;
        }
    }
    if(flag==1){
        cout << "Yes";
        return 0;
    }
    flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(a[n-1-j][i]==1 && a[n-1-j][i]!=b[i][j]){
            flag=0;
        }
    }
    if(flag==1){
        cout << "Yes";
        return 0;
    }
    flag=1;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(a[n-1-i][n-j-1]==1 && a[n-1-i][n-j-1]!=b[i][j]){
            flag=0;
        }
    }
    if(flag==1){
        cout << "Yes";
        return 0;
    }
    flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        if(a[j][n-1-i]==1 && a[j][n-1-i]!=b[i][j]){
            flag=0;
        }
    }
    if(flag==1){
        cout << "Yes";
        return 0;
    }
   cout <<"No";
}