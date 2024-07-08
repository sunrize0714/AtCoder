#include<bits/stdc++.h>
using namespace std;
int h,w;
string s[101];
int main(){
    cin >> h >> w;
    for(int i=0;i<h;i++){
        cin >> s[i];
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='s'){

                if(j+4<w){
                    if(s[i][j+1]=='n' && s[i][j+2]=='u' && s[i][j+3]=='k' && s[i][j+4]=='e'){
                        for(int k=0;k<5;k++){
                            cout << i+1 << " " << j+k+1 << endl;
                        }
                        return 0;
                    }
                }
                    
                if(j>3){
                    if(s[i][j-1]=='n' && s[i][j-2]=='u' && s[i][j-3]=='k' && s[i][j-4]=='e'){
                        for(int k=0;k<5;k++){
                            cout << i+1 << " " << j-k+1 << endl;
                        }
                        return 0;                        }
                }

                if(i+4<h){
                    if(s[i+1][j]=='n' && s[i+2][j]=='u' && s[i+3][j]=='k' && s[i+4][j]=='e'){
                        for(int k=0;k<5;k++){
                            cout << i+k+1 << " " << j+1 << endl;
                        }
                        return 0;
                    }
                }

                if(i>3){
                    if(s[i-1][j]=='n' && s[i-2][j]=='u' && s[i-3][j]=='k' && s[i-4][j]=='e'){
                        for(int k=0;k<5;k++){
                            cout << i-k+1 << " " << j+1 << endl;
                        }
                        return 0;
                    }
                }

                if(i+4<h && j+4<w){
                        if(s[i+1][j+1]=='n' && s[i+2][j+2]=='u' && s[i+3][j+3]=='k' && s[i+4][j+4]=='e'){
                            for(int k=0;k<5;k++){
                                cout << i+k+1 << " " << j+k+1 << endl;
                            }
                            return 0;
                        }
                    }
                if(i>3 && j>3){
                        if(s[i-1][j-1]=='n' && s[i-2][j-2]=='u' && s[i-3][j-3]=='k' && s[i-4][j-4]=='e'){
                            for(int k=0;k<5;k++){
                                cout << i-k+1 << " " << j-k+1 << endl;
                            }
                            return 0;
                        }
                    }

                if(i>3 && j+4<w){
                        if(s[i-1][j+1]=='n' && s[i-2][j+2]=='u' && s[i-3][j+3]=='k' && s[i-4][j+4]=='e'){
                            for(int k=0;k<5;k++){
                                cout << i-k+1 << " " << j+k+1 << endl;
                            }
                            return 0;
                        }
                    }
                if(i+4<h && j>3){
                        if(s[i+1][j-1]=='n' && s[i+2][j-2]=='u' && s[i+3][j-3]=='k' && s[i+4][j-4]=='e'){
                            for(int k=0;k<5;k++){
                                cout << i+k+1 << " " << j-k+1 << endl;
                            }
                            return 0;
                        }
                    }
            }
        }
    }
}
