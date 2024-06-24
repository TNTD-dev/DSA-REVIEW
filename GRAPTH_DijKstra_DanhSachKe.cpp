#include <bits/stdc++.h>
using namespace std;
using ll= long long;

const int INF= numeric_limits<int>::max();
unordered_map<string, list<pair<string,int>>> adjList;
// Dijkstra's algorithm using adjacency list
void Dijkstra(unordered_map<string, list<pair<string,int>>> adjList, string &source, string &destination) 
{
    unordered_map<string,int> distances;
    unordered_map<string,string> parents;
    priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;


    // Khởi tạo distance và pq
    // pq(trong so, dinh)
    for( auto it: adjList)
    {
        distances[it.first]=(it.first==source)? 0: INF;
        pq.push(make_pair(distances[it.first], it.first)) ;
    }

    while(!pq.empty())
    {
        string current=pq.top().second;
        pq.pop();
        // Nếu khoảng cách tối thiểu của node hiện tại là vô cùng (nó không chỉ vào node nào) 
        //và node hiện tại trùng với node cần đi đến
        if(distances[current]==INF) break;
        if(current==destination) break; 

        for( auto it: adjList.at(current))
        {
            string neighbor=it.first;
            int weight=it.second;

            if(distances[current]+weight < distances[neighbor])
            {
                distances[neighbor]=distances[current]+weight;
                parents[neighbor]=current;
                pq.push(make_pair(distances[neighbor],neighbor));
            }
        }
    }

    // In duong di
    if(distances.find(destination)==distances.end() || distances[destination]==INF) 
        cout<<"no_path"<<endl;
    else
    {
        stack<string> path;
        string crawl=destination;
        while(crawl!=source)
        {
            path.push(crawl);
            crawl=parents[crawl];
        }
        path.push(source);
        
        while(!path.empty())
        {
            cout<<path.top();
            path.pop();
            if(!path.empty()) cout<<" ";
        }
        cout<<" "<<distances[destination]<<endl;
    }
}

void Input(int n, int e, unordered_map<string, list<pair<string,int>>> &adjList)
{
    vector<string> vertices(n);
    for(int i=0 ; i<n ;i++)
    {
        cin>>vertices[i];
        adjList[vertices[i]]=list<pair<string,int>>();
    }

    for(int i=0; i<e; i++)
    {
        string u,v;
        int weight;
        cin>>u>>v>>weight;
        adjList[u].push_back(make_pair(v,weight));
        // Nếu đồ thị vô hướng
        //adjList[v].push_back(make_pair(u,weight));
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n,e,m;
    cin>>n>>e;
    Input(n,e,adjList);
    cin>>m;
    while(m--)
    {
        string start,end;
        cin>>start>>end;
        Dijkstra(adjList,start,end);
    }
    
    return 0;
}