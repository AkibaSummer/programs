#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;
long long a[105];
//  b[105];

int prim[100050], pcc, sz;
int nprim[100050];
long long ans[100050];

void sieve(int n)
{
    pcc = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!nprim[i])
        {
            prim[++pcc] = i;
            for (int j = i + i; j <= n; j += i)
            {
                nprim[j] = 1;
            }
        }
    }
}

long long qp(long long x, long long y, long long m)
{
    long long ans = 1;
    x %= m;
    while (y)
    {
        if (y & 1)
            ans = ans * x % m;
        x = x * x % m;
        y >>= 1;
    }
    return ans;
}
bool MillerRabin(long long n)
{
    if (n == 2)
        return 1;
    if (n < 2 || !(n & 1))
        return 0;
    long long m = n - 1;
    long long k = 0;
    while ((k & 1) == 0)
    {
        k++;
        m /= 2;
    }
    for (int i = 0; i < 12; i++)
    {
        long long a = rand() % (n - 1) + 1;
        long long x = qp(a, m, n);
        long long y = 0;
        for (int j = 0; j < k; j++)
        {
            y = x * x % n;
            if (y == 1 && x != 1 && x != n - 1)
                return 0;
            x = y;
        }
        if (y != 1)
            return 0;
    }
    return 1;
}
void gao(long long x, long long y, long long z)
{

    if (x + 1 > prim[pcc] && MillerRabin(x + 1))
    {
        ans[++sz] = (x + 1) * y;
    }

    for (int i = z; i >= 1; i--)
    {
        if (x % (prim[i] - 1) == 0)
        {
            long long t1 = x / (prim[i] - 1);
            long long t2 = y;
            long long c = 1;
            while (t1 % c == 0)
            {
                t2 *= prim[i];
                gao(t1 / c, t2, i - 1);
                c *= prim[i];
            }
        }
    }

    if (x == 1)
    {
        ans[++sz] = y;
        return;
    }
}

long long Phi(long long n)
{
    long long sqrtn = sqrt(n);
    if ((sqrtn + 1) * (sqrtn + 1) == n)
    {
        sqrtn++;
    }
    long long nn = n;
    long long ret = n;
    // printf("QAQQQ %9d:", n);
    for (int i = 1; prim[i] <= sqrtn; i++)
    {
        if (n % prim[i] == 0)
        {
            n /= prim[i];
            while (n % prim[i] == 0)
                n /= prim[i];
            ret = ret / prim[i] * (prim[i] - 1);
            // printf(" %9d:", prim[i]);
        }
    }
    // printf("QAQQQ %9d\n", n);
    if (n > 1)
        ret = ret / n * (n - 1);
    return ret;
}

pair<int, int> s[105];
/*
10000
140001440
140001438

100008488
100014092
100018446


10088106 2261870
10088105 2261869
10088104 2261868
10088103 2261867
10088102 2261866
10088101 2261865
10088100 2261864
10088099 2261863
10088098 2261862
10088097 2261861
10088096 2261860
10088095 2261859
10088094 2261858
10088093 2261857

10052090 2400922
10052089 2400921
10052088 2400920
10052087 2400919
10052086 2400918
10052085 2400917
10052084 2400916
10052083 2400915
10052082 2400914
10052081 2400913
10052080 2400912
10052079 2400911
10052078 2400910
10052077 2400909
10052076 2400908
10052075 2400907
10052074 2400906
10052073 2400905
10052072 2400904
10052071 2400903

9981950 2384620
9981949 2384619
9981948 2384618
9981947 2384617
9981946 2384616
9981945 2384615
9981944 2384614
9981943 2384613

9972812 2277994
9972811 2277993

9964668 2277464
9964667 2277463

9942956 2446948
9942955 2446947
9942954 2446946
9942953 2446945
9942952 2446944
9942951 2446943
9942950 2446942
9942949 2494455
9942948 2494454
9942947 2494453
9942946 2494452
9942945 2494451
9942944 2494450
9942943 2494449
9942942 2494448
9942941 2494447

9876170 2257852
9876169 2257851
9876168 2257850
9876167 2257849
9876166 2257848
9876165 2257847
9876164 2257846
9876163 2257845
9876162 2257844
9876161 2257843

9824540 2064286
9824539 2485947
9824538 2485946
9824537 2485945
9824000
9823772 2244454
9823771 2244453
9823770 2244452
9823769 2244451
*/
int main()
{
    int T;
    sieve(100000);
    // printf("%d\n", Phi(139977191));
    // T = 500;
    scanf("%d",&T);
    // int mxsz= 0;
    while (T--)
    {
        int mxt = 0, mxid;
        // int gg = T + 1000000000;
        // int gg;
        // scanf("%d",&gg);
        for (int i = 1; i <= 100; i++)
        {
            // a[i] = Phi(gg + i);
            // a[i] = 3;
            scanf("%lld",&a[i]);
            // s[i].first = a[i]; s[i].second = i;
            if (mxt < a[i])
            {
                mxid = i;
                mxt = a[i];
            }
        }
        // a[1] = 1;
        sz = 0;
        // printf("orz%d\n", mxt);
        gao(mxt, 1, pcc);
        sort(ans + 1, ans + 1 + sz);
        // mxsz = max(sz, mxsz);
        // printf("sz%d\n", sz);
        // for(int i=1;i<=10;i++) {
        //     printf("%9d ", ans[i]);
        // }
        // puts("");
        // if(gg % 1000 ==0) printf("%d\n",gg);

        // for(int i=1;i<=100;i++) {
        //     printf("%9d: %9d\n", gg+i, a[i]);
        // }
        // // printf("%d %d", mxid, mxt);
        // puts("");

        // sort(s+1,s+1+100);
        int flag = 0, xxx;
        long long buu;
        for (xxx = 1; xxx <= sz; xxx++)
        {
            buu = ans[xxx] - mxid + 1;
            if(buu > 200000000) break;
            // flag = 1;
            // for (int i = 1; prim[i] <= 95; i++)
            // {
            //     if ((xxx + mxid - 1) % prim[i] == 0)
            //     {
            //         flag = 0;
            //         continue;
            //     }
            // }
            // if (!flag)
            //     continue;
            // if(xxx % 1000 ==0) printf("%d\n",xxx);
            // b[s[xxx].second] = s[xxx].first + 1;
            // printf("asserting %d", xxx);
            // for(int i=s[xxx].second-1;i>=1;i--) {
            //     b[i] = b[i+1]-1;
            // }
            // for(int i=s[xxx].second+1;i<=100;i++) {
            //     b[i] = b[i-1]+1;
            // }
            // if(b[1]<1) {
            //     continue;
            // }

            flag = 1;
            for (int i = 1; i <= 100; i++)
            {
                if (Phi(buu + i - 1) != a[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                break;
        }

        // if(buu != gg+1) {
        //     // puts("orzzz");
        //     printf("bad%d %d\n",gg,buu);

        // }

        if (flag)
        {
            puts("YES");
            printf("%d\n", buu);
        }
        else
        {
            puts("NO");
        }
    }
    // printf("%d\n", mxsz);
    // puts("QAQ");
}
/*
1
1 1 2 2 4 2 6 4 6 4
10 4 12 6 8 8 16 6 18 8
12 10 22 8 20 12 18 12 28 8
30 16 20 16 24 12 36 18 24 16
40 12 42 20 24 22 46 16 42 20
32 24 52 18 40 24 36 28 58 16
60 30 36 32 48 20 66 32 44 24
70 24 72 36 40 36 60 24 78 32
54 40 82 24 64 42 56 40 88 24
72 44 60 46 72 32 95 42 60 40

*/