#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>

using namespace std;
class Graph{
     public:
     //for weighted graph
     //unordered_map<int,list<pair<int,int>>>adjList;

     //Not weighted
     unordered_map<int,list<int>>adjList;

     //Graph (V,E),indegree,outdegree
     //Graph can be made using adjacency matrix
     //Graph ->directed/undirected ,weighted/unweighted,
     //Traversal-> bfs,dfs
    

     //storing weight too;
    //  void addEdge(int u,int v,int weight,bool direction){
    //     if(direction==true){
    //         adjList[u].push_back({v,weight});
    //     }
    //     else {
    //         adjList[u].push_back({v,weight});
    //         adjList[v].push_back({u,weight});
    //     }
    //  }

    //  void printAdjList(int n){
    //     for(int i=0;i<n;i++){
    //         cout<<i<<":";
    //         cout<<"{";
    //         list<pair<int,int>>temp=adjList[i];

    //         for(auto nbr:temp){
    //             cout<<"("<<nbr.first<<","<<nbr.second<<")";
    //         }
    //         cout<<"}"<<endl;
    //     }
    //  }
 
     void Bfs(unordered_map<int,list<int>>adj,int src){
        queue<int>q;
        unordered_map<int,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
             int frontNode=q.front();
             cout<<frontNode<<"->";
             q.pop();
             for(auto nbr:adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
             }
        }
        return;
    }



    void dfsHelperF(int src,unordered_map<int,list<int>>adj,unordered_map<int,bool>&visited){
        visited[src]=true;
        cout<<src<<"->";
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                dfsHelperF(nbr,adj,visited);
            }
        }
        return;
    }
    void dfs(unordered_map<int,list<int>>adj,int n){
        unordered_map<int,bool>visited;
        for(int src=0;src<n;src++){
           if(!visited[src]) dfsHelperF(src,adj,visited);
        }
    }
     

     void addEdge(int u,int v,bool direction){
        if(direction==true){
            adjList[u].push_back(v);
        }
        else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
     }

     void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout<<i<<":";
            cout<<"{";
            list<int>temp=adjList[i];

            for(auto nbr:temp){
                cout<<nbr<<",";
            }
            cout<<"}"<<endl;
        }
     }

     void bfsTraversal(int src){
          queue<int>q;
          unordered_map<int,bool>visited;
          q.push(src);
          while(!q.empty()){
            int frontNode=q.front();
            if(!visited[frontNode])cout<<frontNode<<"->";
            visited[frontNode]=true;
            q.pop();
            for(auto nbrs:adjList[frontNode]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                   // visited[nbrs]=true; for directed
                }
            }
          }
          return;
        }

        void dfsHelper(int src,unordered_map<int,bool>& visited){
            visited[src]=true;
            cout<<src<<"->";
            for(auto nbrs:adjList[src]){
                if(!visited[nbrs]){
                    dfsHelper(nbrs,visited);
                }
            }
            return;
        }
        void dfsTraversal(int n){
            unordered_map<int,bool>visited;
            for(int src=0;src<n;src++){
               if(!visited[src]){
                dfsHelper(src,visited);
               }
            }
            return;
        }

};

bool dfsHelperfunc(unordered_map<int,list<int>>adjList,unordered_map<int,bool>& visited,int src,int parent){
   visited[src]=true;
   for(auto nbrs:adjList[src]){
    if(!visited[nbrs]){
        bool ans=dfsHelperfunc(adjList,visited,nbrs,src);
        if(ans)return true;
    }
    else if(visited[nbrs]&&nbrs!=parent) return true;
   }
   return false;
}

bool cycleDetect(unordered_map<int,list<int>>adjList,int n){
   unordered_map<int,bool>visited;
   bool ans=false;
   int parent=-1;
   for(int src=0;src<n;src++){
    if(!visited[src]){
       ans= dfsHelperfunc(adjList,visited,src,parent);
       if(ans)break;
    }
   }
   return ans;
   
}


bool bfsCycleDetect(unordered_map<int,list<int>>adj,int src, unordered_map<int,bool>&visited){
    queue<int>q;
    unordered_map<int,int>parent;
    visited[src]=true;
    parent[src]=-1;
    q.push(src);
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        for(auto nbr:adj[frontNode]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr]=true;
                parent[nbr]=frontNode;
            }
            else if(visited[nbr]==true&&nbr!=parent[frontNode]) return true;
        }
    }
    return false;
}

bool isCycleBfs(unordered_map<int,list<int>>adj,int n){
    unordered_map<int,bool>visited;
    bool ans=false;
    for(int src=0;src<n;src++){
        if(!visited[src]){
           ans=bfsCycleDetect(adj,src,visited);
        }
        if(ans)break;
    }

    return ans;
}

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,9,0);
    g.addEdge(3,8,0);
    int n=6;
    g.printAdjList(n);
    g.bfsTraversal(0);
    cout<<endl;
    g.dfsTraversal(n);
    if(cycleDetect(g.adjList,6))cout<<"cycle present";
     else cout<<"cycle absent";
     cout<<endl;
    if(isCycleBfs(g.adjList,n))cout<<"cycle present";
     else cout<<"cycle absent";

    
    return 0;
}