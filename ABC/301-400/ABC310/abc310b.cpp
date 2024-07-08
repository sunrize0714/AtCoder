#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(n+1,0),c(n+1);
    bool f[101][101];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            f[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        cin >> p[i];
        cin >> c[i];
        for(int j=0;j<c[i];j++){
            int k;
            cin >> k;
            f[i][k] = true;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int flag = 1;
            if(p[i] >= p[j] && i != j){
                for(int k=0;k<m;k++){
                    if(f[i][k] == true && f[j][k] == false){
                        flag = 0;
                        break;
                    }
                }

                if(flag == 1){
                    if(p[i] > p[j]){
                        cout << "Yes";
                        return 0;
                    }
                    for(int k=0;k<m;k++){
                        if(f[i][k] == false && f[j][k] == true){
                            cout << "Yes";
                            return 0;
                        }
                    }
                }
            }    
        }
    }
    cout << "No";
}