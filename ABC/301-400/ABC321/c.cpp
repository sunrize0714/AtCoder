#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll; 
typedef vector<bool> vb;
typedef string str;

int main(){
    ll k;
    cin >> k;
    ll index = 1;
    while(k>0){
        if(index == 9876)index = 43210;
        if(index == 98765)index = 543210;
        if(index == 987654)index = 6543210;
        if(index == 9876543)index = 76543210;
        if(index == 98765432)index = 876543210;
        if(index == 987654321)index = 9876543210;
        ll now = index;
        ll number = now%10;
        now /= 10;
        bool flag = true;
        while(now > 0){
            if(number >= now % 10){
                flag = false;
                break;
            }
            number = now % 10;
            now /= 10;
        }
        if(flag == true){
            k--;
        }
        if(k == 0)cout << index << endl;
        index++;
    }
}