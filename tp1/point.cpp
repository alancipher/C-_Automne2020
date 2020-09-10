/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://ericbeaudry.ca/INF3105/lab1/
  le JEUDI 10/09/2020
INSTRUCTIONS:
  Vous devez compléter ce fichier.
*************************************************/

#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(const Point& point)
  : x(point.x), y(point.y) 
{
}

Point::Point(double  _x, double  _y) 
  : x(_x), y(_y)
{
}


double  Point::distance(const Point& point) const {
  // À compléter

//   sqrt((x1.x2)^2 + (y1 + y2)^2 )
  return sqrt(pow (x-point.x,2) + pow (y-point.y,2));
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
    assert(po=='(');
    assert(vir==',');
    assert(pf==')');
  }
  return is;
}


