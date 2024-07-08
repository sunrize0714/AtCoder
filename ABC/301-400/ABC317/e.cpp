#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }

    int s_x,s_y,g_x,g_y;
    vector<vector<int>> grid(h,vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j] == 'S'){
                s_x = j;
                s_y = i;
            }
            if(a[i][j] == 'G'){
                g_x = j;
                g_y = i;
            }
            if(a[i][j] == '#')grid[i][j] = -1;
            if(a[i][j] == '<'){
                for(int k=j;k>=0;k--){
                    if(a[i][k] == '.' || k == j)
                    grid[i][k] = -1;
                    else{
                        break;
                    }
                }
            }
            if(a[i][j] == '>'){
                for(int k=j;k<w;k++){
                    if(a[i][k] == '.' || k == j)
                    grid[i][k] = -1;
                    else break;
                }
            }
            if(a[i][j] == '^'){
                for(int k=i;k>=0;k--){
                    if(a[k][j] =='.' || k == i)grid[k][j] = -1;
                    else break;
                }
            }
            if(a[i][j] == 'v'){
                for(int k=i;k<h;k++){
                    if(a[k][j] =='.' || k == i)grid[k][j] = -1;
                    else break;
                }
            }
        }
    }
    vector<vector<int>> graph(h*w);
    vector<int> dist(h*w,-1);

    for(int i=0;i<h;i++){
        for(int j=0;j<w-1;j++){
            if(grid[i][j] == 0 && grid[i][j+1] == 0){
                graph[i*w+j].push_back(i*w+j+1);
                graph[i*w+j+1].push_back(i*w+j);
            }
        }
    }

    for(int i=0;i<h-1;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j] == 0 && grid[i+1][j] == 0){
                graph[i*w+j].push_back((i+1)*w+j);
                graph[(i+1)*w+j].push_back(i*w+j);
            }
        }
    }

    queue<int> q;
    q.push(s_y*w+s_x);
    dist[s_y*w+s_x] = 0;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i=0;i<graph[pos].size();i++){
            int to = graph[pos][i];
            if(dist[to] == -1){
                dist[to] = dist[pos] + 1;
                q.push(to);
            }
        }
    }
    cout << dist[g_y*w+g_x];
    
}