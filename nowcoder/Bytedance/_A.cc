#include <bits/stdc++.h>
using namespace std;

typedef struct Point{
    double x,y;
}Point;

inline double sqr(double x){
    return x*x; 
}

inline double dist(double X1,double Y1,double X2,double Y2){
    double sqrx=sqr(X1-X2);
    double sqry=sqr(Y1-Y2);
    return sqrt(sqrx+sqry);
}

inline double calct(double X1,double Y1,double X2,double Y2){
    return dist(X1,Y1,X2,Y2)*sqrt(1/(5*fabs(Y2-Y1)));
}

inline Point getPoint(double sina,double l){
    bool flag=sina>1;
    if (sina>1)sina-=1;
    double y=sina*l;
    double x=sqrt(sqr(l)-sqr(y));
    y=-y;
    if (flag)x=-x;
    return {x,y};
}

double getans(Point){
    
}

int main(){
    cout<<calct(0,0,0,-10)<<endl;
    int Y1(0),Y2(-10);
    int t;
    cin>>t;
    while (t--){
        int x,y,l1,l2,l3;
        cin>>x>>y>>l1>>l2>>l3;
        if (y>0){
            cout<<"Impossible!"<<endl;
            continue;
        }
        else {
            
        }
    }
}