/***from dust i have come, dust i will be***/

#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 1010
#define inf 1e9

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int, int>

using namespace std;

int adj[15][15];
int main()
{
    // freopen("in.txt", "r", stdin);

    int i, j, k;
    int n, m, t;

    sf(t);
    while(t--)
    {
        string s;
        cin >> s;

        n = s.length();
        char a, b;

        cin >> m;
        memset(adj, 0, sizeof(adj));

        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a - 'a'][b - 'a'] = 1;
        }

        for(k = 0; k < 10; k++)
        {
            for(i = 0; i < 10; i++)
            {
                for(j = 0; j < 10; j++)
                {
                    if(adj[i][k] && adj[k][j])
                        adj[i][j] = 1;

                    if(i == j)
                        adj[i][j] = 1;
                }
            }
        }

        for(i = 0; i < 10; i++)
        {
            if(i + 'a' < s[0] && adj[s[0] - 'a'][i])
            {
                s[0] = i + 'a';
                break;
            }
        }

        for(i = 1; i < n; i++)
        {
            for(j = s[i - 1] - 'a'; j < 10; j++)
            {
                if(adj[s[i] - 'a'][j])
                {
                    s[i] = j + 'a';
                    break;
                }
            }
        }

        bool flag = true;
        for(i = 1; i < n; i++)
        {
            if(s[i] < s[i - 1]){
                flag = false;
                break;
            }
        }

        if(flag) pfs("YES\n");
        else pfs("NO\n");
    }

    return 0;
}
