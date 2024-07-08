#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[101];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string st = s[i] + s[j];
            int flag = 1;
            for(int k=0;k<st.size();k++){
                if(st[k] != st[st.size()-1-k]){
                    flag = 0;
                    break;
                }
            }
            if(i != j && flag == 1){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}                                                   