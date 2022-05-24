//BFS

#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;

class Graph{
	int V;
	map<int, list<int>> l;

public:
	Graph(int V){
		this->V = V;
		cout<< "constructor called"<<endl;
	}

	void addEdge(int u , int v){
		l[u].push_back(v);
		l[v].push_back(u);
		cout<< "addEgde called"<<endl;
	}

	void bfs(int src){
		// cout<< "src is : "<<src<<endl;
		map<int, bool> visited;
		queue<int> q;

		q.push(src);

		visited[src] = true;

		while(!q.empty()){
			// cout<< "Q non empty "<<endl;

				int node  = q.front();
				
				// cout<<" node is : "<<node<<endl;

				q.pop();
				for(int nbr : l[node] ){
					// cout<< "neighbour";
					// cout<<" "<<nbr;

					if(visited[nbr] == false){
						q.push(nbr);
						visited[nbr] = true;
						// cout<<"  pushed and visited "<<nbr<<endl;

						cout<<"  BFS OUT "<<nbr<<endl;
					}
					else
						continue;
					
				cout<<endl<<endl;

				
			}//outer for loop
			
		}
	}
};
int main(int argc, char const *argv[])
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(3,4);

//0 -> 1, 2 -> 3 -> 4
	g.bfs(2);

	return 0;
}
