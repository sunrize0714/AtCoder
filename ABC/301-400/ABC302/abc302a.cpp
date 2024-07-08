#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b;
    cin >> a >> b;
    int flag=1;
    if(a%b==0)flag=0;
    cout << a/b+flag;
}