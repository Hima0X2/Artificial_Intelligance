/// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
const int mx =10002;
vector<int> adj[mx];
bool vis[mx];
void dfs(int n){
     vis[n]=1;
     for(auto u:adj[n]){
          if(vis[u]==0){
           dfs(u);
          }
     }
}
int main()
{
     optimize();
    // freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
     long long int t,i,n,m,u,c=0,v;
     cin>>n>>m;
    for(i=1;i<=m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(i=1;i<=n;i++){
if(vis[i]==0){
     c++;
     dfs(i);
    }
}
cout<<c<<endl;

//std::cout << std::fixed << std::setprecision(2);
}
/// ALHAMDULILLAH




