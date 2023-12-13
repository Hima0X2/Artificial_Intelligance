/// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
long long int lcm(long long int a,long long b){
         return a*(b/__gcd(a,b));
    }
const long long int mx = 1003;
char adjMat[mx][mx];
vector<pair<int,int>> adj[mx];
int main()
{
     optimize();
    // freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
     long long int t,n,m,u,v,w;
     cin>>n>>m;
     for(int j=1;j<=m;j++){ //when adj is int index starts with 0
          //cin>>adjMat[i][j];
          cin>>u>>v>>w;
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
     }
     for(int i=1;i<=n;i++){
               cout<<"Adj of "<<i<<": ";
          for(auto u: adj[i]){
               cout<<"Node :"<<u.first<<" Cost:"<<u.second<<" ";
          }
          cout<<endl;
     }
//std::cout << std::fixed << std::setprecision(2);
}
/// ALHAMDULILLAH




