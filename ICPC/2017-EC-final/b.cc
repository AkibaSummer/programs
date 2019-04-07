#include <bits/stdc++.h>
using namespace std;

long double tot;

long double sqr(long double a){
    return a*a;
}

struct node{
    int n;
    long double cost;
    long double q;  //added
    node(int _n,long double _cost){
        n=_n;cost=_cost;
        q=sqr(cost/(n+1)-tot)*(n+1)-sqr(cost/n-tot)*n;
    }
    bool operator <(const node p)const{
        return q>p.q;
    }
};

int input[200005];

int main(){
    int t;
    scanf("%d",&t);
    for (int tt=1;tt<=t;tt++){
        int n,m,mm;
        scanf("%d %d",&n,&m);
        mm=m;
        
        priority_queue<node> que;
        tot=0;
        for (int i=1;i<=n;i++){
            // cin>>input[i];
            scanf("%d",input+i);
            tot+=input[i];
        }
        tot/=m;
        for (int i=1;i<=n;i++){
            que.push(node(1,input[i]));
        }
        m-=n;
        while (m--){
            node temp=que.top();
            que.pop();
            que.push(node(temp.n+1,temp.cost));
        }

// puts("");
        long double ans=0;
        while (!que.empty()){
            node temp = que.top();
            ans+=sqr(temp.cost/temp.n-tot)*temp.n;
            que.pop();
            // cout<<temp.n<<' '<<temp.cost<<endl;
        }
        printf("Case #%d: %.12Lf\n",tt,ans/mm);
// puts("");
    }
}