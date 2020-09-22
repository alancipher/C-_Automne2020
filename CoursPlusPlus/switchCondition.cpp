#include <iostream>

using namespace std;

int main()
{
    int nbEnfants(5);

    switch (nbEnfants)
    {
        case 0:
            cout << "Eh bien alors, vous n'avez pas d'enfant ?" << endl;
            break;

        case 1:
            cout << "Alors, c'est pour quand le deuxieme ?" << endl;
            break;

        case 2:
            cout << "Quels beaux enfants vous avez la !" << endl;
            break;

        default:
            cout << "Bon, il faut arreter de faire des gosses maintenant !" << endl;
            break;
    }

    return 0;
}
