#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v2[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
   cout<<u<<" ";
    for(int v:v2[u])
    {
        if(visited[v]==true)continue;
        dfs(v);
    }

}
int main()
{
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        v2[u].push_back(v);


    }
   dfs(2);//source zekhan theke suru korte bolce

return 0;
}