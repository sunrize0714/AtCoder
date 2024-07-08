#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,x,y;
    cin >> n >> x >> y;
    vector<long long int> p(n-1),t(n-1);
    for(int i=0;i<n-1;i++)cin >> p[i] >> t[i];
    long long int ans = 0;
    for(int i=0;i<n-1;i++)ans += t[i];
    ans += x + y;
    //cout << ans << endl;

    vector<long long int> adds(16800,0);
    for(long long int i=1680;i<3370;i++){
            long long int addtime = 0;
            long long int nowtime = i+x;

        for(long long int j=0;j<n-1;j++){
            if(nowtime%p[j] != 0){
                addtime += (p[j] - nowtime%p[j]);
                nowtime += (p[j] - nowtime%p[j]);
            }
            nowtime += t[j];
        }
        adds[i-1680] = addtime;
    }

    long long int q;
    cin >> q;
    vector<long long int> Q(q);
    for(long long int i=0;i<q;i++)cin >> Q[i];
    
    for(long long int i=0;i<q;i++){
        cout << Q[i] + ans + adds[Q[i]%1680] << endl;
    }

}