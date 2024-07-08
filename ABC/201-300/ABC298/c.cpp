#include<bits/stdc++.h>
using namespace std;
long long int amari[11][610000],retu[610000];
int main(){
    int q;
    cin >> q;
    for(int i=1;i<10;i++){
        long long int a = i;
        amari[i][1] = a;
        for(int j=2;j<610000;j++){
            amari[i][j] = (amari[i][j-1]*10)%998244353;
        }
    }
    

    long long int ans=1,start=1,goal=1; 
    retu[1] = 1;
    for(int i = 0;i<q;i++){
        int y,x;
        cin >> y;
        if(y == 1){
            cin >> x;
            retu[goal+1] = x;
            ans*=10;
            ans+=x;
            goal++; 
        }
        if(y == 2){
            int bi = 1;
            for(int j=start;j<goal;j++)bi*=10;
            ans -= retu[start]*bi;
            start++;
        }
        if(y == 3){
           /* for(long long int p=start;p<=goal;p++){
                ans += amari[retu[p]][goal-p+1];
                if(ans>90000000)ans = ans%998244353;
            }*/
            cout << ans << endl;
        }
    }
}