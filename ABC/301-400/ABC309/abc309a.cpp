#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    if(a%3 == 1){
        if(a+1 == b)cout << "Yes";
        else cout << "No";
    }
    else if(a%3 == 2){
        if(b-1 == a)
            cout << "Yes";
        else cout << "No";
        
    }
    else cout << "No";

}