#include <bits/stdc++.h>

using namespace std;
struct machine {
    int u, r, t; //t last start
    int uu, rr;
} orz[15];

int ac(machine &mac, int t) { //ret:end time
    int ret;
    if (t < mac.t) { // zhi jie kai shi (ta hai mei kai shi)
        ret = t + mac.uu + mac.rr;
        mac.t = max(mac.t, t + mac.uu);
    } else {
        mac.t = (t - mac.t) / (mac.u + mac.r) * (mac.u + mac.r) + mac.t;
        int mod = (t - mac.t) % (mac.u + mac.r);
        if (mod < mac.u) { // deng dai jie shu
            ret = mac.t + mac.u + mac.uu + mac.rr;
            mac.t = max(mac.t + mac.u + mac.uu, mac.t + mac.r + mac.u);
        } else { // zhi jie kai shi
            ret = t + mac.uu + mac.rr;
            mac.t = max(mac.t + mac.u + mac.r, t + mac.uu);
        }
    }
    return ret;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        cin >> orz[i].uu >> orz[i].rr;
    }
    for (int i = 1; i <= 10; i++) {
        cin >> orz[i].u >> orz[i].r >> orz[i].t;
    }
    int t = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            t = ac(orz[j], t);
            //cout<<i<<' '<<j<<' '<<t<<' '<<orz[j].t<<endl;
        }
    }
    cout << t - orz[10].rr;
}