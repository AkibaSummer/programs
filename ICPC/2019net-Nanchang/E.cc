#include <iostream>
#include <vector>
using namespace std;

int getans(int totnum, int start, int wanted, int m) {
  if (start > totnum) {
    return getans(totnum, start - totnum, wanted, m);
  }
  if ((wanted - start) % m == 0) {
    return (wanted - start) / m + 1;
  } else {
    int nowchose = (totnum - start) / m + 1;
    int nstart = (totnum - start) / m * m + m + start - totnum;
    if (start <= nstart)
      nstart + 1;
    int ntotnum = totnum - nowchose;
    if (nstart == 0)
      nstart = m;
    int nwanted;
    if (wanted < start)
      nwanted = wanted;
    else {
      nwanted = wanted - (wanted - start) / m - 1;
    }
    // cout << ntotnum << ' ' << nstart << ' ' << nwanted << ' ' << m << endl;
    return getans(ntotnum, nstart, nwanted, m) + nowchose;
  }
}

int slove() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> query(q);
  for (int i = 0; i < q; i++)
    cin >> query[i];
  for (int i = 0; i < q; i++) {
    cout << getans(n, 1, query[i], m + 1) << endl;
  }
  // for (int i = 1; i <= 6; i++) {
  //	cout << getans(6, 1, i, 4) << endl;
  //}
  return 0;
}

int main() {
  int t;
  cin >> t;
  // t = 1;
  while (t--) {
    slove();
  }
}