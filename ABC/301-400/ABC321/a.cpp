#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;
typedef string str;

int main(){
    string s;
    cin >> s;
    int t = s.size();
    for(int i=0;i<t-1;i++){
        if(s[i] - '0' <= s[i+1] - '0'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}