#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> field(n);
    for(int i=0;i<n;i++){
        cin >> field[i];
    }
    vector<vector<bool>> touch(n,vector<bool>(m,false));
    int ans = 1;
    touch[1][1] = true;
    
}