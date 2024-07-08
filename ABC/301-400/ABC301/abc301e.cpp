#include<bits/stdc++.h>
using namespace std;
int h,w,t,now=0,start,goal;
vector<int> g[100000];
string a[310];
int okasi[20],dist[100000]={-1};
queue<int> q;
int main(){
    cin >> h >> w >> t;
    for(int i=0;i<h;i++){
        cin >> a[i];
        for(int j=0;j<w;j++){
            if(a[i][j]=='S')start = (i-1)*w+j;
            if(a[i][j]=='G')goal = (i-1)*w+j;
            if(a[i][j]=='o'){
                okasi[now] =(i-1)*w+j;
                now++;
            }
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w-1;j++){
            if(a[i][j]!='#' && a[i][j+1]!='#'){
                g[(i-1)*w+j].push_back((i-1)*w+j+1);
                g[(i-1)*w+j+1].push_back((i-1)*w+j);
            }
        }
    }

    for(int i=0;i<h-1;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]!='#' && a[i+1][j]!='#'){
                g[(i-1)*w+j].push_back(i*w+j);
                g[i*w+j].push_back((i-1)*w+j);
            }
        }
    }

    q.push(start);
    dist[start]=0;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i=0;i<g[pos].size();i++){
            int to = g[pos][i];
            if(dist[to] == -1){
                dist[to] = dist[pos] + 1;
                q.push(to);
            }
        }
    }

    if(t < dist[goal]){
        cout << -1 << endl;
        return 0;
    }
    int point=0,standing=goal;
    for(int i=dist[goal];i>0;i--){
        for(int j=0;j<g[standing].size();j++){
            if(dist[g[standing][j]] = i-1){
                standing = g[standing][j];
                if(a[standing/w])
            }
        }
    }

    for(int i=0;i<now;i++){
        okasi[i]=min(dist[okasi[i]],abs(dist[goal]-dist[okasi[i]]));
    }
    sort(okasi,okasi+now);
    int left = t-dist[goal];
    for( ){}
}