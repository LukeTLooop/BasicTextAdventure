/*
 * Storyline game with
 * - a beginning
 * - 3 endings
 * - 3 choices for progression (2 options)
 * - choice validation
 * Horror story, murderer is chasing you
 * If you escape the killer you win
 * - start chase
 * - woods or abandoned church
 * - WOODS
 *  - to creek
 *  - to church
 *  - CREEK
 *   - die
 *  - CHURCH
 *   - to basement
 *    - win
 *   - to street
 *    - die
 * - CHURCH
 *  - die
 */

#include <iostream>

using namespace std;

int promptChoice(string choice1, string choice2)
{
    int option;

    while (true)
    {
        cout << "Run to " << choice1 << "(1) or " << choice2 << "(2): ";
        cin >> option;

        if (option == 1 || option == 2)
            break;
        
        cout << "Select a valid answer!\n";
    }

    return option;
}

int main()
{
    int option;

    // INTRO
    cout << "RUN!\n";
    cout << "A killer is targeting you as their next victim, choose the right path to survive!\n\n";

    // CHOICE 1
    option = promptChoice("WOODS", "ABANDONED CHURCH");
    switch (option)
    {
        case 1:
            // correct
            cout << "While running through the woods, you evaded the killer and gained some distance!\n";
            break;
        case 2:
            // incorrect
            cout << "On your way to the church, the killer caught up and sliced you!\n";
            return -1;
    }

    // CHOICE 2
    option = promptChoice("CREEK", "CHURCH");
    switch (option)
    {
        case 1:
            // incorrect
            cout << "You run through the creek and get your shoes wet which severely slows your speed, the killer grabs you and lays the finishing blow!\n";
            return -1;
        case 2:
            // correct
            cout << "In a split second decision you make a wide turn and head toward the church!\n";
            break;
    }

    // CHOICE 3
    option = promptChoice("BASEMENT", "STREET");
    switch (option)
    {
        case 1:
            // correct
            cout << "In the church you arm yourself with a weapon and hide, then when the time is right you strike the killer!\n";
            break;
        case 2:
            // incorrect
            cout << "Since the basement is obviously a trap, you run to the street! You are slowed down by an incoming car and caught by the killer!\n";
            return -1;
    }

    cout << "You have successfully escaped the killer!";

    return 0;
}
