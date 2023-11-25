#include<bits/stdc++.h>
using namespace std;
int n = 9;
vector<int> ans = {1, 2, 3, 4, 5, 6, 7, 8, 0};
map<vector<int>, bool> visit;

struct node {
    vector<int> state;
    node* parent;
    node()
    {
        parent = NULL;
    }
};
void printState(vector<int> state)
{
    for(int i = 0; i < 9; )
    {
        for(int j = 0; j < 3; ++j, ++i)
            cout << state[i] << " ";
        cout << endl;
    }
    cout << endl;
}
void printPath(node* state)
{
    vector<node*> path;
    while(state)
    {
        path.push_back(state);
        state = state->parent;
    }

    cout << "Moves Required: " << path.size()-1 << endl;
    for(int i = path.size()-1; i >= 0; --i)
        printState(path[i]->state);
}
node* createNewState(node* state, int x, int y)
{
    node* new_state = new node();
    new_state->state = state->state;
    swap(new_state->state[x], new_state->state[y]);

    return new_state;
}
void BFS(node* start_state)
{
    visit[start_state->state] = 1;

    int pos, row, col;

    node *curr = new node();
    node *child = new node();
    queue<node*> q;
    q.push(start_state);

    while(!q.empty())
    {
        curr = q.front();
        q.pop();

        if(curr->state == ans)
        {
            printPath(curr);
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            if(curr->state[i] == 0)
            {
                pos = i;
                break;
            }
        }
        row = pos / 3;
        col = pos % 3;

        if(col != 0)
        {
            child = createNewState(curr, pos, pos-1);

            if(visit[child->state] == 0)
            {
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(col != 2)
        {
            child = createNewState(curr, pos, pos+1);

            if(visit[child->state] == 0)
            {
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(row != 0)
        {
            child = createNewState(curr, pos, pos-3);

            if(visit[child->state] == 0)
            {
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }

        if(row != 2)
        {
            child = createNewState(curr, pos, pos+3);

            if(visit[child->state] == 0)
            {
                visit[child->state] = 1;
                child->parent = curr;
                q.push(child);
            }
        }
    }
}
int main()
{
    int x;
    node* start = new node();
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        start->state.push_back(x);
    }
    BFS(start);
    return 0;
}
/*
2 4 3 7 1 5 0 8 6
*/
