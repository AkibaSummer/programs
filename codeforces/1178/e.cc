#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000005;

string s;
int len;
bool used[maxn];
int t;
void find(char cmp)
{
    memset(used, 0, sizeof(used));
    int cnt = 0;
    for (int i = 1; i <= len; i++)
    {
        if (s[i] == cmp)
        {
            cnt++;
            used[i] = 1;
        }
    }
    int posl = 1, posr = len;
    int sl = 0, sr = 0;
    while (posl <= posr)
    {
        if (s[posl] == cmp)
            posl++, sl++;
        else if (s[posr] == cmp)
            posr--, sr++;
        else if (s[posl] == s[posr])
        {
            if (sl == sr)
            {
                cnt++;
                used[posl] = 1;
                used[posr] = 1;
                posl++;
                posr--;
            }
            else if (sl < sr)
                posl++;
            else
                posr--;
        }
        else
        {
            if (sl == sr)
                posl++;
            else if (sl < sr)
                posl++;
            else
                posr--;
        }
    }
    if (cnt >= t)
    {
        for (int i = 1; i <= len; i++)
            if (used[i])
                cout << s[i];
        cout << endl;
        exit(0);
    }
}
int main()
{
    cin >> s;
    s = " " + s;
    len = s.length() - 1;
    t = len / 2;
    find('a');
    find('b');
    find('c');
    cout << "IMPOSSIBLE" << endl;
    return 0;
}