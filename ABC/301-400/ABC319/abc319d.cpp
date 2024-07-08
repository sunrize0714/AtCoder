#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m;
    cin >> n >> m;
    vector<long long int> l(n);
    for(int i=0;i<n;i++)cin >> l[i];
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    long long int maxi = 0;
    for(int i=0;i<n;i++)maxi = max(maxi,l[i]);

    long long int low = maxi,high = 9223372036850000;
    while(high >= low){
        long long int mid = (low + high)/2;
        vector<long long int> space(m,mid);
        long long int pos = 0;
        space[pos] -= l[0];
        for(long long int i=1;i<n;i++){
            if(space[pos] >= l[i]+1)space[pos] -= l[i]+1;
            else{
                pos++;
                if(pos < m){
                    space[pos] -= l[i];
                }
                else{
                    low = mid+1;
                    break;
                }
            }
            
            if(i == n-1 && space[m-1] >= 0){
                high = mid-1;
                break;
            }
        }

    }
    cout << high+1 << endl;
}