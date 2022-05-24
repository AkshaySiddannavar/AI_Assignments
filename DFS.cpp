//dfs

#include <stack>
#include <iostream>
#include <list>
#include <map>

using namespace std;

class Graph{
	int V;
	map<int, list<int>> l;

public:
	Graph(int V){
		this->V = V;
		cout<< "constructor ran"<<endl;
	}

	void addEdge(int u , int v){
		l[u].push_back(v);
		l[v].push_back(u);
		cout<< "add Edge ran"<<endl;
	}

	void dfsHelper(int src, map<int, bool> &visited){
		//since we are sending visited as &visited so when value is changed in recursive calls it is updated in visited
		//hence we don't need to return visited
		cout<<src<<" ";

		visited[src] = true;

		for(int nbr: l[src]){

			if(visited[nbr] == false){
				dfsHelper(nbr, visited);
			}
		}
	}//automatically control is transferred back to calling function
	void dfs(int src){

		map<int, bool> visited;

		for(auto p: l){
			int node = p.first;
			visited[node] = false;
		}	
		
		//recursive

		//dfs(neighbour) for each neighbour

		//go down in graph/tree

		//1. find neighbours
		//2. go to neighhbours
		//3. find their neghouts
		//till empty
		//start printout 
		
		dfsHelper(src, visited);

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
	g.dfs(0);
	return 0;
}