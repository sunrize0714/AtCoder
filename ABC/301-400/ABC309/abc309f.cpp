#include<bits/stdc++.h>
using namespace std;

vector<tuple<long long int,long long int,long long int>> b;
int main(){
    int n;cin >> n;
    for(int i=0;i<n;i++){
        long long int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        b.push_back(make_tuple(a[0],a[1],a[2]));
    }

    sort(b.begin(),b.end(),greater<tuple<long long int,long long int,long long int>>());
    for(int i=0;i<n-1;i++){
            
            
            
            
            long long int small1 = get<0>(b[i+1]) - get<0>(b[i]);
            long long int small2 = get<1>(b[i+1]) - get<1>(b[i]);
            long long int small3 = get<2>(b[i+1]) - get<2>(b[i]);

            if(small1 < 0  && small2 < 0 && small3 < 0){
                cout << "Yes";
                return 0;
            }
            
     
    }
    if((get<0>(b[n-1]) < get<0>(b[0])) &&(get<1>(b[n-1]) < get<1>(b[0])) && (get<2>(b[n-1]) < get<2>(b[0]))){
    cout << "Yes" << endl;
    return 0;
    }
    cout << "No";
}
  