/// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
long long int lcm(long long int a,long long b){
         return a*(b/__gcd(a,b));
    }
const long long int mx = 1e7+123;
long long int a[mx];
void bfs (long long int s )
{
    memset( lev, -1,sizeof(lev) );
    queue<int> q;
    q.push( s );
    lev[s]= 0;
    while ( !q.empty() ) {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        for ( auto v : adj[u] ) {
            if ( lev[v] == -1 ) {
                lev[v] = lev[u] + 1;
                par[v] = u;
                q.push( v );
            }
        }
    }
    cout<<endl;
}
int main()
{
     optimize();
    // freopen("a.txt","r",stdin);freopen("b.txt","w",stdout);
     long long int t,i,n;
      int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].PB ( v );
        adj[v].PB ( u );
    }
    int s = 1;
    bfs (s);

//std::cout << std::fixed << std::setprecision(2);
}
/// ALHAMDULILLAH




