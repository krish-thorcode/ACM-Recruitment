#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;			 
	list<int> *adj;	 
					
public:
	Graph(int V);	
	void addEdge(int v, int w);
	void longestPathLength();
	pair<int, int> bfs(int u);
							
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v-1].push_back(w-1);
	adj[w-1].push_back(v-1);
}


pair<int, int> Graph::bfs(int u)
{
	int dis[V];
	memset(dis, -1, sizeof(dis));

	queue<int> q;
	q.push(u);

	dis[u] = 0;

	while (!q.empty())
	{
		int t = q.front();	 q.pop();

		for (auto it = adj[t].begin(); it != adj[t].end(); it++)
		{
			int v = *it;

			if (dis[v] == -1)
			{
				q.push(v);

				dis[v] = dis[t] + 1;
			}
		}
	}

	int maxDis = 0;
	int nodeIdx;
	for (int i = 0; i < V; i++)
	{
		if (dis[i] > maxDis)
		{
			maxDis = dis[i];
			nodeIdx = i;
		}
	}
	return make_pair(nodeIdx, maxDis);
}

void Graph::longestPathLength()
{
	pair<int, int> t1, t2;

	t1 = bfs(0);

	t2 = bfs(t1.first);

	cout << t2.second;
}

int main()
{
	int cities;
	cin>>cities;
	Graph g(cities);
	int u,v;

	for(int i=0;i<cities-1;i++)
	{
		cin>>u>>v;
		g.addEdge(u,v);
	}

	g.longestPathLength();
	return 0;
}
