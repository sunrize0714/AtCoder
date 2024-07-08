#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> sleep_len(n);
    sleep_len[0] = 0;
    for(int i=1;i<n;i++){
        if(i%2 == 1)sleep_len[i] = sleep_len[i-1];
        else sleep_len[i] = sleep_len[i-1] + (a[i] - a[i-1]);  
    }

    cin >> q;
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        int start = lower_bound(a.begin(),a.end(),l) - a.begin();
        int end = lower_bound(a.begin(),a.end(),r) - a.begin();
        int ans = sleep_len[end] - sleep_len[start];
        if(start != end){
            if(start % 2 == 0)ans += (a[start] - l);
            if(end % 2 == 0)ans -= (a[end] - r);
        }
        if(start == end && start % 2 == 0){
            ans = r-l;
        }
        if(start == end && start % 2 == 1)ans = 0;
        cout << ans << endl; 
    }
}