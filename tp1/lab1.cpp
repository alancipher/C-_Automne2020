/************************************************
  Laboratoire 1
  INF3105 | Structures de données et algorithmes
  UQAM | Département d'informatique
  Source: http://ericbeaudry.ca/INF3105/lab1/
*************************************************/

#include <iostream>
#include "point.h"

/************************************************************************
INSTRUCTIONS:
   Suivez rigoureusement les tâches à http://ericbeaudry.ca/INF3105/lab1/.
   NE sautez PAS d'étape !
   Si vous sautez une étape ou tentez d'aller trop rapidement,
   alors vous risquez d'introduire des bogues!
*************************************************************************/
/*
int main(int argc, const char** args)
{
  std::cout << "Bienvenue au cours INF3105 en C++ !" << std::endl;
  return 0;
}

int main(int argc, const char** args)
{
  Point point(3, 105);
  std::cout << point;
  std::cout << std::endl; // fin de ligne
  return 0;
}  


int main(int argc, const char** args)
{
  Point point(1.2,5.7);
  std::cout << "point.x=" << point.x << "\tpoint.y=" << point.y << std::endl;
  return 0;
} 


int main(int argc, const char** args)
{
  Point point;
  std::cout << "Entrez un point:" << std::endl;
  std::cin >> point;
  std::cout << "Revoici votre point:" << std::endl;
  std::cout << point << std::endl;
  return 0;
}

int main(int argc, const char** args)
{
  Point a(0,0);
  Point b(4,3);
  double d = a.distance(b);
  std::cout << "Distance("<< a << "," << b << ")=" << d << std::endl;
  return 0;
}  */

int main(int argc, const char** args)
{
  int nb;
  std::cin >> nb;
  Point* points = new Point[nb];// le new veux dire que le tableau est cree sur le tas 
   // un delete est donc important  a la fin de l'allocation pour eviter fuite 
  // de memoire 
    for (int i = 0; i<nb; ++i)
       std ::cin >> points[i];


double min = std:: numeric_limits<double>::infinity() ;

for(int i=1; i<nb ; i++){
 for(int j = 0; j<i; j++){
double d = points[i].distance(points[j]);
if (d<min)
   min =d;
}
}

delete[] points;

  return 0;
}


