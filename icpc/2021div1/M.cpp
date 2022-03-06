#include<bits/stdc++.h>
#include<vector>
using namespace std;

const int lg=17;
int test_cases,n,m,up[18][100003],par[100003],lev[100003];
vector<int>g[100003];
vector<int>permutation;

void DFS(int u)
{
    for(int i=0;i<g[u].size();++i)
    {
        int v=g[u][i];
        if(v!=par[u])
        {
            lev[v]=lev[u]+1,par[v]=u;
            DFS(v);
        }
    }
}

void BuildTable()
{
    for(int i=0;i<=lg;++i)
        for(int j=1;j<=n;++j)
            up[i][j]=-1;
    for(int i=1;i<=n;++i)
        up[0][i]=par[i];
    for(int i=1;i<=lg;++i)
        for(int j=1;j<=n;++j)
            if(up[i-1][j]!=-1)
                up[i][j]=up[i-1][up[i-1][j]];
}

int LCA(int u,int v)
{
    if(lev[u]<lev[v]) swap(u,v);
    for(int i=lg;i>=0;--i)
        if(lev[u]-(1<<i)>=lev[v]) u=up[i][u];
    if(u==v) return u;
    for(int i=lg;i>=0;--i)
        if(up[i][u]!=-1 && up[i][u]!=up[i][v]) u=up[i][u],v=up[i][v];
    return up[0][u];
}

int verify()
{
    for(int i = 0; i < permutation.size() - 1; ++i)
    {
        int u = permutation[i];
        int v = permutation[i + 1];
        int r = LCA(u, v);

        if (lev[u] + lev[v] - 2 * lev[r] > 3)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> test_cases;
    for(int i = 0; i < test_cases; ++i)
    {
        cin >> n;
        for(int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            par[u] = par[v] = 0;
            lev[u] = lev[v] = 0;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        lev[1] = 1;
        par[1] = -1;
        DFS(1);
        BuildTable();

        for(int i = 0; i < n; ++i)
        {
            int vertex;
            cin >> vertex;
            permutation.push_back(vertex);
        }
        cout << verify();
        for(int i = 1; i <= n; ++i)
        {
            g[i].clear();
        }
        permutation.clear();
    }
}