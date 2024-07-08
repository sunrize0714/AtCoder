#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    int co = 0;
    for(int i=0;i<n;i++){

        if(s[i] == '(')co++;
        if(s[i] != ')')
        st.push(s[i]);
        else if(s[i] == ')' && co > 0){
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
            co--;
        }
        else st.push(s[i]);
    }

    stack<char> ans;
    while(!st.empty()){
        char s = st.top();
        ans.push(s);
        st.pop();
    }
    
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }

}  