#include<bits/stdc++.h>
using namespace std;
int main(){
    string s[10];
    int rate[10];
    s[0]="tourist",rate[0]=3858;
s[1]="ksun48",rate[1]=3679;
s[2]="Benq", rate[2]=3658;
s[3]="Um_nik", rate[3]=3648;
s[4]="apiad", rate[4]=3638;
s[5]="Stonefeang", rate[5]=3630;
s[6]="ecnerwala", rate[6]=3613;
s[7]="mnbvmar", rate[7]=3555;
s[8]="newbiedmy", rate[8]=3516;
s[9]="semiexp", rate[9]=3481;
string t;
cin >> t;
for(int i=0;i<10;i++){
    if(t == s[i])cout << rate[i] << endl;
}
}