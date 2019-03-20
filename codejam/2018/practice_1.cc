#include <bits/stdc++.h>
using namespace std;

int input[100];

int main(){
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        for (int j=0;j<n;j++){
            cin>>input[j];
        }
        cout<<"Case #"<<i<<":";
        while (true){
            int max1,max2;
            if (input[0]>input[1]){
                max1=0,max2=1;
            }
            else max2=0,max1=1;
            
            for (int i=2;i<n;i++){
                if (input[i]>=input[max1]){
                    max2=max1;
                    max1=i;
                }
                else if (input[i]>=input[max2]){
                    max2=i;
                }
            }
            if (input[max1]==0){
                cout<<endl;
                break;
            }
            else if (input[max1]==input[max2]){
                    cout<<' '<<(char)(max1-'A')<<(char)(max2-'A');
                    input[max1]--;
                    input[max2]--;
            }
            else {
                cout<<' '<<(char)(max1-'A');
                input[max1]--;
            }
            
        }
    }
}