#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,m;
    cin >> n >> t >> m;
    vector<int> a(m),b(m);
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
    }

    if(t == n){
        cout << 1 << endl;
        return 0;
    }

    long long int bit = 1;
    for(long long int i=0;i<t;i++){
        bit *= t;
    }
    for(long long int i=1;i<=bit;i++){
        
    }
    
}