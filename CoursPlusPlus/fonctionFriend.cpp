#include <iostream>
#include <fstream>
# include <assert.h> 
class Point {
private:
  double x,y;
friend std :: istream& operator >> (std::istream& is , Point& p);
friend std :: ostream& operator << (std::ostream& os, const Point& p);
} ;

std :: istream& operator >> (std::istream& is , Point& p){
char parouvr, vir, parferm;
is >> parouvr >> p.x >> vir >> p.y >>parferm;
assert(parouvr=='(' && vir== ',' && parferm == ')');
return is;
}
std :: ostream& operator << (std::ostream& os, const Point& p){ 

os << "(" << p.x << "," << p.y << ")";
return os;
}
