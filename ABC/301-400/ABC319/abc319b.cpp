#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    vector<long long int> f(n),j(10);
    for(int i=1;i<=9;i++){
        if(n%i == 0)j[i] = 1;
        else j[i] = 0;
    }
    for(int i=0;i<=n;i++){
        bool flag = false;
        for(int k=1;k<=9;k++){
            if(i%(n/k) == 0 && j[k] == 1){
                cout << k ;
                flag = true;
                break;
            }
        }
        if(flag ==  false)cout << "-";
        
    }
    
}