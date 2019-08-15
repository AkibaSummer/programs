#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    // cin>>n;
    while(~scanf("%d",&n)){
    vector<int> minn(n),midd(n),maxx(n),uni(3*n);
    for (int i=0;i<n;i++){
        scanf("%d%d%d",&minn[i],&midd[i],&maxx[i]);
        uni[i*3]=minn[i];
        uni[i*3+1]=midd[i];
        uni[i*3+2]=maxx[i];
    }
    sort(uni.begin(),uni.end());
    // uni.erase(unique(uni.begin(),uni.end()),uni.end());
    for (auto &i:minn)i=lower_bound(uni.begin(),uni.end(),i)-uni.begin();
    for (auto &i:midd)i=lower_bound(uni.begin(),uni.end(),i)-uni.begin();
    for (auto &i:maxx)i=lower_bound(uni.begin(),uni.end(),i)-uni.begin();



    vector<int> maxxmidd(3*n+5),middminn(3*n+5);
    for (auto &i:minn)middminn[i+1]++;
    for (auto &i:midd)middminn[i]--,maxxmidd[i+1]++;
    for (auto &i:maxx)maxxmidd[i]--;
    for (int i=1;i<3*n+3;i++){
        middminn[i]+=middminn[i-1];
        maxxmidd[i]+=maxxmidd[i-1];
    }

    
    // for (int i=0;i<3*n+3;i++){
    //     printf("%d %d\n",middminn[i],maxxmidd[i]);
    //     // uni[i*3]=minn[i];
    //     // uni[i*3+1]=midd[i];
    //     // uni[i*3+2]=maxx[i];
    // }

    for (int i=0;i<n;i++){
        int ret=maxxmidd[midd[i]]+middminn[midd[i]];
        printf("%d\n",ret);
    }
    // vector<int> yminn=minn,ymidd=midd,ymaxx=maxx;
    // sort(minn.begin(),minn.end());
    // sort(midd.begin(),midd.end());
    // sort(maxx.begin(),maxx.end());
    // for (int i=0;i<n;i++){
    //     int lost=minn.end()-lower_bound(minn.begin(),minn.end(),ymidd[i])  +  midd.end()-lower_bound(midd.begin(),midd.end(),ymaxx[i])  -  (minn.end()-lower_bound(minn.begin(),minn.end(),ymaxx[i]));
    //     int win=lower_bound(maxx.begin(),maxx.end(),midd[i])-maxx.begin()  +  lower_bound(midd.begin(),midd.end(),yminn[i])-midd.begin()  -  (lower_bound(maxx.begin(),maxx.end(),yminn[i])-maxx.begin());
    //     // cout<<lost<<' '<<win<<' '<<n-1-lost-win<<endl;
    //     // cout<<n-1-lost-win<<endl;
    //     printf("%d\n",n-1-lost-win);
    // }
    }
}