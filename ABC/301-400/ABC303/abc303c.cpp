#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<long long int,long long int>> items;
    for(int i=0;i<m;i++){
        long long int x,y;
        cin >> x >> y;
        items.insert({x,y});
    }
    long long int movex[4] = {1,-1,0,0};
    long long int movey[4] = {0,0,1,-1};
    string moji = "RLUD";
    long long int now_x=0,now_y=0,hitpoint=h;
    for(long long int i=0;i<n;i++){
        for(long long int j=0;j<4;j++){
            if(s[i] == moji[j]){
                now_x += movex[j];
                now_y += movey[j];
            }
        }

        hitpoint--;
        if(hitpoint < 0){
            cout << "No" << endl;
            return 0;
        }

        if(hitpoint < k && items.count({now_x,now_y})){
            hitpoint = k;
            items.erase({now_x,now_y});
        }
        
    }

    cout << "Yes" << endl;
}