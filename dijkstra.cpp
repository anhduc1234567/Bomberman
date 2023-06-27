#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dijkstraByQueue(vector<pair<int,int>> adj[], int source, int size, int target) {
    vector<int> distance(size , 10000);
    bool * unvisited = new bool[size];
    for(int i = 1; i < size ; i++) {
        unvisited[i] = true;
    }
    distance[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    // < khoang cách, đỉnh nguồn đến đó>
    Q.push({0,source});
    while(!Q.empty()) {
        pair<int,int> top = Q.top();
        Q.pop();
        int u = top.second; // đinh
        int w  = top.first;
        if(u == target) return distance[u];
        if(unvisited[u] == true) {
            unvisited[u] = false;
            for(auto i : adj[u]) {
                int v = i.first;
                int weight =  i.second;
                if(distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    Q.push({distance[v],v});
                }
            } 
        }
    }
    return -1;
} 
int main() {
    int n;
    cout << " nhap so dinh\n";
    cin >> n;
    vector<pair<int,int>> adj[n];
    cout << "nhap canh \n";
    int start,end,weight;
    while(true) {
        cout <<"start end weight  :";
        cin >> start;
        if(start == -1) break;
        cin >> end;
        cin >> weight;
        adj[start-1].push_back({end-1,weight});
    }
    dijkstraByQueue(adj,0,n,4);


}