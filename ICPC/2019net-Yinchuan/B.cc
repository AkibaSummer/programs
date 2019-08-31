#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int input[100][3];
double len[100], angle[100];

double sqr(int a) { return a * a; }

double getangle(double x1, double y1, double x2, double y2, double x,
                double y) {
  double tenta = atan2(x1 - x, y1 - y) - atan2(x2 - x, y2 - y);
  if (tenta > PI)
    tenta -= 2 * PI;

  if (tenta < -PI)
    tenta += 2 * PI;
  tenta = tenta * 180 / PI;
  return abs(tenta);
}

void slove() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> input[i][1] >> input[i][2];
  }
  input[n + 1][1] = input[1][1];
  input[n + 1][2] = input[1][2];
  input[n + 2][1] = input[2][1];
  input[n + 2][2] = input[2][2];
  int x, y;
  cin >> x >> y;
  for (int i = 2; i <= n + 1; i++) {
    len[i] = sqrt(sqr(input[i][1] - x) + sqr(input[i][2] - y));
    // cerr<<len[i]<<' ';
  }
  //   cerr<<endl;
  for (int i = 2; i <= n + 1; i++) {
    angle[i] = getangle(input[i - 1][1], input[i - 1][2], input[i + 1][1],
                        input[i + 1][2], input[i][1], input[i][2]);
    // cerr<<angle[i]<<' ';
  }
  //   cerr<<endl;
  double ans = 0;
  for (int i = 2; i <= n + 1; i++) {
    ans += 2 * PI * len[i] * (180 - angle[i]) / 360;
  }
  cout << fixed << setprecision(3) << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    slove();
  }
}