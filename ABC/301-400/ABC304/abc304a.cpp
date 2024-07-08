#include<bits/stdc++.h>
using namespace std;
string s[101];
long long int mini = 2000000000, a[101];
int main(){
    int n;
    cin >> n;
    for(long long int i=1;i<=n;i++){
        cin >> s[i] >> a[i];
        if(a[i]<mini)mini = a[i];
    }

    for(long long int i=1;i<=n;i++){
        if(mini == a[i]){
            for(long long int j=i;j<=n;j++){
                cout << s[j] << endl;
            }
            if(i != 1){
                for(long long int j=1;j<i;j++){
                    cout << s[j] << endl;
                }
            }
            return 0;
        }
        
    }
}