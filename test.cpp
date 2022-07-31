#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define M 1e9 + 7
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    TC(t)
    {
        ll N, X;
        cin >> N >> X;
        if (X <= ceil(N / 2.0f))
        {
            string temp1 = "", temp2 = "";
            char c = 'a';
            for (int i = 0; i < N / 2; i++)
            {
                if (X > 0)
                {
                    temp1 += c;
                    c++;
                    X--;
                }
                temp1 += temp1[temp1.size() - 1];
            }
            temp2 = temp1;
            reverse(temp2.begin(), temp2.end());
            if (N % 2 == 0)
                cout << temp1 << temp2;
            else
                cout << temp1 << 'z' << temp2;
        }
        else
            cout << -1;
        cout<<endl;
    }
    return 0;
}