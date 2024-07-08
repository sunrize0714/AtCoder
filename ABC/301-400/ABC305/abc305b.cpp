#include<bits/stdc++.h>
using namespace std;
int main(){
    char p,q;
    cin >> p >> q;
    string s = "ABCDEFG";
    int ans[7]={0,3,4,8,9,14,23};
    int n = abs(ans[(int)p-'A']-ans[(int)q-'A']);
    cout << n;
}