/// BISMILLAHIR RAHMANIR RAHIM
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
const int mx = 1e5+123;
vector<int> adj[mx];
int lev[mx];
int par[mx];

void bfs ( int s )
{
    memset( lev, -1,sizeof(lev) );
    queue<int> q;
    q.push( s );
    lev[s]= 0;

    while ( !q.empty() ) {
        int u = q.front();
        q.pop();

        for ( auto v : adj[u] ) {
            if ( lev[v] == -1 ) {
                lev[v] = lev[u] + 1;
                par[v] = u;
                q.push( v );
            }
        }
    }
}


int main()
{
    optimize();

    int n, m;
    cin >> n >> m;

    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].PB ( v );
        adj[v].PB ( u );
    }

    int s = 1, t = 6;
    bfs (s);

    if ( lev[s] == -1 ) {
        cout << "No route\n";
        return 0;
    }

    vector<int> path;
    par[s] = -1;

    while ( t != -1 ) {
        path.PB ( t );
        t = par[t];
    }

    reverse( path.begin(), path.end() );

    for ( auto u : path ) cout << u << " ";
    cout << endl;

    return 0;
}
