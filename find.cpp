#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int col=35;
const int row=11;
class Peak {
public:
    int i;
    int j;
    int lable;
    Peak() {

    }
    Peak(int i, int j, int n) {
        this->i = i;
        this->j = j;
        this->lable = n;
    }
     friend ostream& operator << (ostream&os,const Peak& v){
         os << "( " << v.i << " - " << v.j << " )";
	         return os;
      }
    
};
  int getN(const vector<Peak>&v, int i, int j) {
        for(auto k : v) {
            if(k.i==i && k.j == j) {
                return k.lable;
            }
        }
    }

void dijkstraByQueue(vector<pair<int,int>> adj[], int source, int size, int target, int *path, int *distance) {
    //int *distance = new int[size]();
    bool *unvisited = new bool[size];
    for(int i = 0; i < size; i++) {
        unvisited[i] = true;
      //  distance[i] = 10000;
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
        
        if(unvisited[u] == true) {
            unvisited[u] = false;
            for(auto i : adj[u]) {
                int v = i.first;
                int weight =  i.second;
                if(distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    Q.push({distance[v],v});
                    path[v] = u;
                }
            } 
        }
    }
   // return -1;
} 
Peak getV(const vector<Peak>&v,int n) {
    for(auto k : v) {
        if(k.lable==n) {
            return k;
        }
    }
    } 
 void showPath(int * path, int target, int source,vector<Peak> ver) {
         cout<< getV(ver,target);
        int pre = path[target];
         while (true)
         {
             cout<<"<-" << getV(ver,pre);
            if(pre == source) break;
             pre = path[pre];
         } 
        
     }
//////////////////////////
int main() {
  int map[row][col]={  
                                                       //0 cỏ có thể đi và đặt bom
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//1 đá không thể phá
        { 1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1 },//2 tường có thể phá
        { 1,3,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },//3 vị trí nhân vật
        { 1,2,2,0,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },//4
        { 1,2,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },//5
        { 1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },//6
        { 1,2,1,2,1,0,1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },//7
        { 1,0,2,2,2,0,2,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },//8
        { 1,2,1,2,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },//9
        { 1,2,0,2,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },//9
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//10
    };
    int n=0;
    vector<Peak> vertise;
    for(int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j++)
        {
           if(map[i][j]!=1&&map[i][j]!=2) {
             vertise.push_back(Peak(i,j,n++));
           }
        }
    }

    cout<<vertise.size() <<endl;
      vector<pair<int,int>> adj[vertise.size()];
      int *distance = new int[vertise.size()];
      for(int i = 0; i< vertise.size(); i++) {
        distance[i] = 10000;
      }
      int * path = new int[vertise.size()];
       for(int i = 0; i < row; i ++) {
         for (int j = 0; j < col; j++)
         {
            if(map[i][j]!=1 && map[i][j]!=2) {
              if(map[i][j+1]==0||map[i][j+1]==3) {
                adj[getN(vertise,i,j)].push_back({getN(vertise,i,j+1),1});
                adj[getN(vertise,i,j+1)].push_back({getN(vertise,i,j),1});
              }
              if(map[i+1][j]==0||map[i+1][j]==3)  {
                adj[getN(vertise,i +1 ,j)].push_back({getN(vertise,i,j),1});
                adj[getN(vertise,i,j)].push_back({getN(vertise,i + 1,j),1});
                }
             }
        }
     }
     cout <<"nhap toa do\n";
     int x,y;
     cin >> x>> y;
     cout << "nhap toa do source\n";
     int k,h;
     cin >> k >> h;
     int source = getN(vertise,k,h);
     int target = getN(vertise,x,y);
     cout << source<<endl;
     dijkstraByQueue(adj,source,vertise.size(),target,path,distance);
    cout<< distance[target] <<endl;
    showPath(path,target,source,vertise);
    cout <<endl;

    for(int i = 0; i < row; i ++) {
        for (int j = 0; j < col; j++)
        {
           cout << map[i][j] <<"  ";
        }
        cout<<endl;
        cout<<endl;        
    }
}