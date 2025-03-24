#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
      bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
          // code 
          vector<int>color(v, 0);      // initilly no vertex is coloured
          return colorVertex(v, edges,0, m, color);
      }
      bool colorVertex(int v, vector<pair<int, int>>& edges, int currentNode, int m, vector<int>& color){
          if(currentNode >= v){       // reached at last vertex so I have colored all vertex
              return true;
          }
          
          for(int i = 1 ; i <= m ; i++){      // because 0 is my not colored status
              color[currentNode] = i;
              if(!isVaildColor(currentNode, edges, color)){
                  continue;
              }
              if(colorVertex(v, edges, currentNode+1, m, color)){
                  return true;
              }
              color[currentNode] = 0;
          }
          return false;
          
          
      }
      
      bool isVaildColor(int currentNode, vector<pair<int, int>>& edges, vector<int>& color){
          for(int i = currentNode-1 ; i>= 0 ; i--){
              for(auto& e : edges){
                  if( (e.first == currentNode && e.second == i) || (e.second == currentNode && e.first == i) ){
                      if(color[currentNode] == color[i]){
                          return false;
                      }
                  }
              }
          }
          return true;
      }
  };

  int main(){
    int m = 3;
    int v = 4;
    vector<pair<int, int>> edges = {{0,1}, {1,2},{2,3},{3,0}, {0,2}};
    Solution s;
    cout << "hi"<< endl;
    cout  <<  s.graphColoring(v, edges, m);
    cout << "hello" << endl;
  }