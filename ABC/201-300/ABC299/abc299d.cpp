#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,r;
    cin >> n;
    l = 0,r = n;
    while(true){
      cout << "? " << (l+r)/2 << endl;
      
      int turn;
      cin >> turn;
      if(turn == 0){
        l = (l+r)/2;
      }
      else{
        r = (l+r)/2;
      }
      
      if(r-l==1){
        cout << "! " << l << endl;
        return 0;
      }
    }
}