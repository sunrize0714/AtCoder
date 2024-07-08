#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[9];
    for(int i=0;i<8;i++){
        cin >> a[i];
    }
    for(int i=0;i<8;i++) 
    if(a[i] < 100 || a[i] > 675 || a[i]%25 != 0){
            cout << "No" ;
            return 0;
        }
    for(int i=1;i<8;i++){
        if(a[i-1] > a[i]){
            cout << "No";
            return 0;
        }
    }
    
    cout << "Yes" << endl;
}