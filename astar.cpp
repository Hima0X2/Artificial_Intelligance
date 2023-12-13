#include <algorithm>
#include <climits>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ll long long
#define all(x) x.begin(),x.end()
#define pii pair<int,int>

struct Node{
    int curCost, tmpCost, edgeCost, id;
};
struct CompareAge {
    bool operator()(const Node& n1, const Node& n2) const {
        return n1.tmpCost > n2.tmpCost;
    }
};

const int N = 1000, inf = 1e9;
vector<Node>g[N];
vector<int>h(N), Parent(N), actualCost(N,inf);
int goal;

void astar(int u){
    priority_queue<Node,vector<Node>, CompareAge>pq;

    Node nw;
    nw.curCost = 0;
    nw.edgeCost = 0;
    nw.id = u;
    nw.tmpCost = h[u];

    pq.push(nw);

    while(!pq.empty()){
        Node par = pq.top(); pq.pop();
        for(int i=0;i<g[par.id].size();i++){
            Node child = g[par.id][i];
            child.curCost = par.curCost+child.edgeCost;
            child.tmpCost = child.curCost+h[child.id];
            if(actualCost[child.id]>child.curCost){
                Parent[child.id] = par.id;
                actualCost[child.id] = child.curCost;
            }
            pq.push(child);
        }
    }
    
}

void solve(){
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,c; cin >> u >> v >> c;

        Node nw;
        nw.curCost = inf;
        nw.edgeCost = c;
        nw.id = v;

        g[u].push_back(nw);
    }
    for(int i=0;i<n-1;i++){
        cin >> h[i];
    }
    goal = n-1;
    astar(0);
    cout << actualCost[goal] << '\n';
    while(goal!=0){
        cout << goal << " <- ";
        goal = Parent[goal];
    }
    cout << goal << '\n';
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t=1; //cin >> t;
    while(t--){
        solve();
    }
}

/*
example taken from: https://www.youtube.com/watch?v=tvAh0JZF2YE&t=628s&ab_channel=GateSmashers
input: 
7 9
0 1 4
0 2 3
1 4 12
1 3 5
2 4 10
2 5 7
3 6 16
4 6 5
5 4 2

14 12 11 11 4 6 0
*/