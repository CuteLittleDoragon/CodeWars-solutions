#include <vector>
using namespace std;
vector<int> snail(vector<vector<int>> &snail_map) {
  vector<int> path;
  while(snail_map.size() >0 and snail_map[0].size()>0){
  for(int i{0};i<snail_map[0].size();i++){
  path.push_back(snail_map[0][i]);
  }
  int width = snail_map[0].size();
  snail_map.erase(snail_map.begin());
  if(snail_map.size() <= 0){
      return path;
  }else{
  width = snail_map[0].size();
  for(int i{0};i<snail_map.size();i++){
  path.push_back(snail_map[i][width-1]);
  }
  width = snail_map[0].size();
  for(int i{0};i < snail_map.size();i++){
        snail_map[i].erase(snail_map[i].begin()+ width -1);
    }
  width = snail_map[0].size();
  int height = snail_map.size();
  for(int i{height-1};i>-1;i--){
  path.push_back(snail_map[height-1][i]);
  }
  snail_map.pop_back();
  height = snail_map.size();
  for(int i{height-1};i>-1;i--){
  path.push_back(snail_map[i][0]);
  }
    for(int i{0};i < snail_map.size();i++){
        snail_map[i].erase(snail_map[i].begin());
    }
  }
  }
  
  
  return path;
}
