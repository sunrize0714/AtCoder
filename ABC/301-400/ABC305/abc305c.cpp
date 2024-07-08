#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> s(h+1,vector<int>(w+1));
    for(int i=1;i<=h;i++){
        string moji;
        cin >> moji;
        for(int j=1;j<=w;j++){
            if(moji[j-1]=='.')s[i][j] = 0;
            else s[i][j] = 1;
        }
    }

    vector<int> wa_h(h+1);
    vector<int> wa_w(w+1);

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            wa_h[i] += s[i][j];
            wa_w[j] += s[i][j];
        }
    }
    int max_h=0,max_w=0;
    for(int i=1;i<=h;i++){
        max_h = max(wa_h[i],max_h);
    }

    for(int j=1;j<=w;j++){
        max_w = max(max_w,wa_w[j]);
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(wa_h[i] == max_h-1 && wa_w[j] == max_w-1)
            cout << i << " " << j;
        }
    }
}