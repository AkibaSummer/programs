#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  double a, b;
  cin >> n >> m >> a >> b;
  vector<vector<double>> qw(1000, vector<double>(5, 0));
  double answer = 1.00;
  qw[1][1] = 1;
  if (n == 2) {
    for (int i = 2; i <= m; i++) {
      qw[i][1] += qw[i - 1][2] * b;
      qw[i][1] += qw[i - 1][1] * (1 - a);

      qw[i][2] += qw[i - 1][1] * a;
      qw[i][2] += qw[i - 1][2] * (1 - b);

      // assert(abs(qw[i][1] + qw[i][2] - 1.0) < 0.00001);
      answer += qw[i][1];
    }
  } else {
    for (int i = 2; i <= m; i++) {
      qw[i][1] += qw[i - 1][1] * (1 - a);
      qw[i][1] += qw[i - 1][2] * b * (1 - a);
      qw[i][1] += qw[i - 1][3] * b * b;

      qw[i][2] += qw[i - 1][1] * a;
      qw[i][2] += qw[i - 1][2] * (1 - a) * (1 - b) + qw[i - 1][2] * a * b;
      qw[i][2] += qw[i - 1][3] * b * (1 - b) * 2;

      qw[i][3] += qw[i - 1][2] * a * (1 - b);
      qw[i][3] += qw[i - 1][3] * (1 - b) * (1 - b);

      // cout << i << '\t' << qw[i][1] << '\t' << qw[i][2] << '\t' << qw[i][3]
      //      << '\t' << abs(qw[i][1] + qw[i][2] + qw[i][3] - 1.0) << endl;
      // assert(abs(qw[i][1] + qw[i][2] + qw[i][3] - 1.0) < 0.00001);
      answer += qw[i][1];
    }
  }
  cout << fixed << setprecision(8) << answer << endl;
}