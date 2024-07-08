#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,h,n,min=1000000,max=-1;
    cin >> w >> h >> n;
    long long int a,b;
    vector<int> p(n),q(n);
    for(int i=0;i<n;i++){
        cin >> p[i] >> q[i];
    }
    cin >> a;
    vector<int> linea(a+1);
    for(int i=1;i<=a;i++)cin >> linea[i];
    cin >> b;
    vector<int> lineb(b+1);
    for(int i=1;i<=b;i++)cin >> lineb[i];
    linea[0] = 0,lineb[0] = 0;
    multiset<long long int> set;
    int ind=0;
    for(int i=0;i<n;i++){
        int pos_a = p[i], pos_b = q[i];
        long long int piece_x = lower_bound(linea.begin(),linea.end(),pos_a) - linea.begin();
        long long int piece_y = lower_bound(lineb.begin(),lineb.end(),pos_b) - lineb.begin();
        long long int in = piece_x*(b+1) + piece_y;
        set.insert(in);
    }
    
        for(auto it = set.begin(); it != set.end(); it = set.upper_bound(*it)){
            int straw = set.count(*it);
            ind++;
            if(straw > max)max = straw;
            if(straw < min)min = straw;
        }
    if((a+1)*(b+1)>(long long int)ind)min = 0;
    cout << min << " " << max;
}