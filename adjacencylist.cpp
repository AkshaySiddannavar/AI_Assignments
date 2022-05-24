//adjacency list 


#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int>*  l;
    
    public:
    
    Graph(int V){
        this->V = V;
        
        l = new list<int>[V];
        cout<<"constructor ran "<<endl;
    }
    
    void addEdge(int u , int v, bool bidir = true){
        l[u].push_back(v);
        if(bidir == true){
            l[v].push_back(u);
        }
        cout<<"add Edge ran "<<endl;
    }
    
    void display(){
        for(int i = 0 ; i< V ; i++){
            cout<<"Source : "<<i<<"->";
            for(int nbr: l[i]){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    
    g.display();
    return 0;
}
