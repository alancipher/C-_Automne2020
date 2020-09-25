#include <assert.h>
#include "point.h"

Point::Point(double _x, double _y)
  : x(_x), y(_y){
// std::cerr << "Point::Point(double, double)" << std::endl;
}
Point::Point(const Point& point)
  : x(point.x), y(point.y){
 //std::cerr << "Point::Point(const Point&)" << std::endl;
}
Point::~Point(){
//std::cerr << "Point::~Point()" << std::endl;
}
double Point::distance(const Point& point) const {

  // TODO
  return sqrt(pow(x-point.x,2)+ pow(y-point.y, 2));
}
std::ostream& operator << (std::ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}
std::istream& operator >> (std::istream& is, Point& point) {
  char po, vir, pf;
  is >> po;
  if(is){
    is >> point.x >> vir >> point.y >> pf;
    assert(po=='(');    assert(vir==',');    assert(pf==')');
  }
  return is;
}
