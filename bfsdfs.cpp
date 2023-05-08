#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
bool vis[N];
vector<int> adj[N];

void input_nodes()
{

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        adj[i].clear(); // clear the adjacency list for each node
    }

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter Edge" << i + 1 << ":" << endl;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void BFS()
{
    for (int i = 1; i <= N; i++)
    {
        vis[i] = 0;
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        vector<int>::iterator it;

        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it])
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
}

void DFS(int node)
{

    if (vis[node])
    {
        return;
    }

    // preorder
    vis[node] = 1;
    cout << node << " ";

    // inorder
    vector<int>::iterator it;

    for (it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (it != adj[node].end() && !vis[*it])
        {
            DFS(*it);
        }
    }
}

int main()
{

    input_nodes();

    int choice;

    do
    {
        cout << "1.BFS" << endl;
        cout << "2.DFS" << endl;
        cout << "3.Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "BFS: ";
            BFS();
            cout << endl;
            break;

        case 2:

            // for (int i = 1; i <= N; i++)
            // {
            //   vis[i] = 0;
            // }
            cout << "DFS: ";
            DFS(1);
            cout << endl;
            break;

        default:
            break;
        }

        cout << endl;
    } while (choice != 3);
    return 0;
}