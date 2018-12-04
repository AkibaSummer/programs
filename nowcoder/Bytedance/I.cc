#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        //string //out;
        string s;
        vector<pair<int,int>> output;
        cin>>s;
        int q(0),w(0),e(0);
        for (auto i:s){
            if (i=='0')q++;
            else if(i=='1')w++;
            else if(i=='2')e++;
        }
        if (q>w+e+1||w>q+e+1||e>q+w+1){
            printf("-1\n");
            //puts("-1");
            continue;
        }
        if (q<=1&&w<=1&&e<=1){
            goto otpt;
        }
        //output.push_back({"%d\n",min(min(max(q+w-2,e-1),max(q+e-2,w-1)),max(w+e-2,q-1)));
        while (w>1&&e>1&&q<=(w-1)+(e-1)+1){
            output.push_back({q+w,q+w+1});
            --w;--e;
            //out+="12";
        }
        //c//out<<q<<w<<e<<endl;
        if (q==w+e+1){
            while (q>2){
                if (w){
                    //out+="01";
                    output.push_back({q,q+1});
                    --q;--w;
                }
                else {
                    //out+="02";
                    output.push_back({q,q+1});
                    --q;--e;
                }
            }
            output.push_back({1,1});
            //out+="0";
            q--;
            goto otpt;
        }
        else if (w==q+e+1){
            if (e){
                output.push_back({q+1,q+1});
                w--;
                //out+="1";
            }
            while (w>1){
                output.push_back({q,q+1});
                --q;--w;
                //out+="01";
            }
            goto otpt;
        }
        else if (e==q+w+1){
            while (e>1){
                output.push_back({q+w,q+w+1});
                if (w){
                    //out+="12";
                    w--;e--;
                }
                else {
                    //out+="02";
                    q--;e--;
                }
            }
            goto otpt;
        }
        
        
        if (w<=1){
            while (q>1&&e>1){
                if (w==1){
                    output.push_back({q,q+2});
                    --q;--w;--e;
                    //out+="012";
                }
                else {
                    output.push_back({q,q+1});
                    --q;--e;
                    //out+="01";
                }
            }
            if (q==1&&e==1&&w==3){
                output.push_back({2,2});
                output.push_back({1,2});
                --w;--w;--q;
                //out+="1";
                //out+="01";
            }
            while (q>2){
                output.push_back({q,q+1});
                if (w){
                    //out+="01";
                    w--;
                    q--;
                }
                else {
                    e--;
                    q--;
                    //out+="02";
                }
            }
            if (q>1){
                output.push_back({1,1});
                //out+="0";
                q--;
            }
            if (w>1){
                output.push_back({1,2});
                //out+="01";
                --q;--w;
            }
            while (e>1){
                output.push_back({q+w,q+w+1});
                if (w>0){
                    --w;--e;
                    //out+="12";
                }
                else if (q>0){
                    --q;--e;
                    //out+="02";
                }
            }
        }
        else {
            while (q>1&&w>1){
                output.push_back({q,q+1});
                --q;--w;
                //out+="01";
            }
            while (q>1&&e>1){
                if (w==1){
                    output.push_back({q,q+2});
                    --q;--w;--e;
                    //out+="012";
                }
                else {
                    output.push_back({q,q+1});
                    --q;--e;
                    //out+="01";
                }
            }
            if (q==1&&e==1&&w==3){
                output.push_back({2,2});
                output.push_back({1,2});
                --w;--w;--q;
                //out+="1";
                //out+="01";
            }
            while (q>2){
                output.push_back({q,q+1});
                if (w){
                    //out+="01";
                    w--;
                    q--;
                }
                else {
                    e--;
                    q--;
                    //out+="02";
                }
            }
            if (q>1){
                output.push_back({1,1});
                //out+="0";
                q--;
            }
            if (w>1){
                output.push_back({1,2});
                //out+="01";
                --q;--w;
            }
            while (e>1){
                output.push_back({q+w,q+w+1});
                if (w>0){
                    --w;--e;
                    //out+="12";
                }
                else if (q>0){
                    --q;--e;
                    //out+="02";
                }
            }
        }/*
        if (e>0)//out="2"+//out;
        if (w>0)//out="1"+//out;
        if (q>0)//out="0"+//out;
        //c//out<<//out<<endl;*/
        otpt:
        cout<<output.size()<<"\n";
        for (auto &i:output)cout<<i.first<<' '<<i.second<<"\n";
    }
}