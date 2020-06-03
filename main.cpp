#include <iostream>
#include "Tree.h"

using namespace std;


int main()
{
    BinTree<int>* tree = NULL;

    int In=NULL;

    while (In != 6)
    {
        cout <<"\n"<<"Choose an operation: " <<endl;
        cout << "1) Insert elements;\n"
            "2) Delete element;\n"
            "3) Search element;\n"
            "4) Print tree;\n"
            "5) Clear tree;\n"
            "6) Exit;\n" << endl;

        cout << "Enter: ";
        cin >> In;

        if (In == 1)
        {
            int s;
            int n;
            cout << "Quantity of elements: ";
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                cin >> s;
                Insert(tree, s);
            }
        }

        if (In == 2)
        {
            cout << "Input element: ";
            int p;
            cin >> p;
            Delete(tree, p);
            cout << endl;
        }

        if (In == 3)
        {
            cout << "Input element: ";
            int q;
            cin >> q;
            isContains(tree, q);
            cout << endl;
        }

        if (In == 4)
        {
            cout << "Tree: " << endl;
            print(tree);
        }

        if (In == 5)
        {
            Clear(tree);
            cout << endl;
            cout << "Tree deleted!";
        }
    }

    return 0;
}
