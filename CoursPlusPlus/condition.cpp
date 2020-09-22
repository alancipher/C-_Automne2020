#include <iostream>

using namespace std;

int main()
{
    int nbEnfants(2);

    if (nbEnfants == 0)
    {
        cout << "Eh bien alors, vous n'avez pas d'enfant ?" << endl;
    }
    else if (nbEnfants == 1)
    {
        cout << "Alors, c'est pour quand le deuxieme ?" << endl;
    }
    else if (nbEnfants == 2)
    {
        cout << "Quels beaux enfants vous avez la !" << endl;
    }
    else
    {
        cout << "Bon, il faut arreter de faire des gosses maintenant !" << endl;
    }

    cout << "Fin du programme" << endl;
    return 0;
}
