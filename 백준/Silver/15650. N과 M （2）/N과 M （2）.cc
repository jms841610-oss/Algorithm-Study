#include <iostream>
#include <vector> 

using namespace std;

int N,M;

void one_solve(){
    for(int i=1;i<=N;i++){
            cout << i << "\n";
    }
    return;
}
void two_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            cout << i << " " << j << "\n";
        }
    }  
    return;  
}
void three_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
    return;
}
void four_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int n=k+1;n<=N;n++){
                    cout << i << " " << j << " " << k << " " << n << "\n";
                }
            }
        }
    }
    return;
}
void five_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int n=k+1;n<=N;n++){
                    for(int m=n+1;m<=N;m++){
                        cout << i << " " << j << " " << k << " " << n << " " << m << "\n";
                    }
                }
            }
        }
    }
    return;
}
void six_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int n=k+1;n<=N;n++){
                    for(int m=n+1;m<=N;m++){
                        for(int a=m+1;a<=N;a++){
                            cout << i << " " << j << " " << k << " " << n << " " << m << " " << a << "\n";
                        }
                    }
                }
            }
        }
    }
    return;
}
void seven_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int n=k+1;n<=N;n++){
                    for(int m=n+1;m<=N;m++){
                        for(int a=m+1;a<=N;a++){
                            for(int b=a+1;b<=N;b++){
                                cout << i << " " << j << " " << k << " " << n << " " << m << " " << a << " " << b << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}
void eight_solve(){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int n=k+1;n<=N;n++){
                    for(int m=n+1;m<=N;m++){
                        for(int a=m+1;a<=N;a++){
                            for(int b=a+1;b<=N;b++){
                                for(int c=b+1;c<=N;c++){
                                    cout << i << " " << j << " " << k << " " << n << " " << m << " " << a << " " << b << " " << c << "\n";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    if(M==1) one_solve();
    if(M==2) two_solve();
    if(M==3) three_solve();
    if(M==4) four_solve();
    if(M==5) five_solve();
    if(M==6) six_solve();
    if(M==7) seven_solve();
    if(M==8) eight_solve();

    return 0;
}