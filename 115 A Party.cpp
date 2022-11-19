#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
typedef long long ll;
const int INF = 3000;
vector<int> graph[2001];
vector<int> roots ;
bool vis[2001];
int dist[2001];
void augmentedBFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    dist[src]=0;
    while (!q.empty())
    {
        int parent =q.front();
        q.pop();
        for (auto child : graph[parent])
        {
            if (!vis[child])
            {
                vis[child]=true;
                q.push(child);
                dist[child]=1+dist[parent];
            }
        }
    }
}



int main()
{

    //freopen("a.txt", "r", stdin);
    int absmax = 0;
    memset (vis,false,sizeof(vis));
    for (int i=0;i<2001;i++)
    {
        dist[i]=INF;
    }
    int n;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        int x ;
        cin >> x;
        if (x!=-1)
        {
            graph[x-1].pb(i);
        }
        else
        {
            roots.pb(i);
        }
    }

    for (auto i : roots)
    {
        memset (vis,false,sizeof(vis));
        for (int j=0;j<2001;j++)
        {
            dist[j]=INF;
        }
        int locmax = 0;
        augmentedBFS(i);
        for (int j=0;j<=2000;j++)
        {
            if (dist[j]<INF)
            {
                locmax =max(locmax,dist[j]);
            }
            //cout << dist[j]<<endl;
        }
        //cout << locmax<<endl;
        absmax =max(absmax,locmax);

    }

    cout << absmax+1;


    return 0;
}
