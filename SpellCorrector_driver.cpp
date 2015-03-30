#include "SpellCorrector.h"
 
using namespace std;
 
int main()
{
    SpellCorrector corrector;
 
    corrector.load("big.txt");
 
    string request;
    while (request != "quit")
    {
        cout << "Type one word\n";
        cin >> request;
 
        string correct(corrector.correct(request));
 
        if (correct != "")
            cout << "Did you mean: " << correct << "?\n\n\n";
        else
            cout << "No corrections avaiable\n\n\n";
    }
 
    return 0;
}