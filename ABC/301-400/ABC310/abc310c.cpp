#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<string> s;
    for(int i=0;i<n;i++){
        string c;
        cin >> c;
        string c2(c);
        reverse(c2.begin(),c2.end());
        if(s.count(c) == 0 && s.count(c2) == 0)
        s.insert(c);
    }
    int ans = s.size();
    cout << ans;
}