#include <vector>
using namespace std;
class DoubleLinear
{
public:
    
    static int dblLinear(int n){
      vector<int> vect{};
      vect.push_back(1);
      int x{0};
      int y{0};
      for(int i{0};i<n;i++){
        int nextX = vect[x]*2+1;
        int nextY = vect[y]*3+1;
        if(nextX <= nextY){
          vect.push_back(nextX);
          x++;
          if(nextX == nextY){
            y++;
          }
        } else{
          vect.push_back(nextY);
          y++;
        }
        }
      
      return vect[n];
    };
};
