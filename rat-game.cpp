#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <limits.h>

void generatingNumbers();
using namespace std;

int main()
{
    int inhand_cash;
    int bet_amount;
    int hole_to_go_into;
    int hole_that_the_cheese_is_in;
    string leave;

    cout << "How much money do you have?" << endl;
    cout << "Enter money:";
    cin >> inhand_cash;
    while ((inhand_cash <= 0) || (cin.fail())) //validates the cash amount
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid amount, please try again" << endl;
        cin >> inhand_cash;
    }
    cout << "You have this much cash: " << inhand_cash << endl;

    while (inhand_cash > 0)
    { //this is the main while loop. when this is not true, the program ends.
        cout << "Place your bet:" << endl;
        cin >> bet_amount;
        while (((bet_amount <= 0) || (bet_amount > inhand_cash)) || (cin.fail()))
        { //validates the bet amount
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid amount, please try again" << endl;
            cin >> bet_amount;
        }
        inhand_cash = inhand_cash - bet_amount;
        cout << "You bet this much:" << bet_amount << endl;
        cout << "This is how much cash you have left after your bet:" << inhand_cash << endl;

        hole_that_the_cheese_is_in = rand() % 3 + 1; //randomizes the hole
        cout << "Guess where the cheese is (enter 1-3)" << endl;
        cin >> hole_to_go_into;
        while (((hole_to_go_into <= 0) && hole_to_go_into <= 3) || (cin.fail()))
        { //validates the hole input
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid amount, please enter (1, 2, or 3)" << endl;
            cin >> hole_to_go_into;
        }
        if (hole_to_go_into == hole_that_the_cheese_is_in)
        { //checks to see if you were correct
            cout << "You got it right!" << endl;
            inhand_cash = inhand_cash + (2 * bet_amount);
            cout << "This is how much cash you have now:" << inhand_cash << endl;
        }
        else
        { //if you were not correct...
            if (inhand_cash <= 0)
            { //if youre out of money
                cout << "You ran out of cash! Game over!" << endl;
            }
            else
            { //if you have some money left over
                cout << "You were wrong, you have this much money left:" << inhand_cash << endl;
                cout << "Do you want to exit the game with the money you have? (enter y/n)" << endl;
                cin >> leave;
                while ((leave != "y") && (leave != "n"))
                { //if neither y nor n is pressed, it will ask you to try again.
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "Invalid input (enter either y or n)" << endl;
                    cin >> leave;
                }
                if (leave == "y")
                { //if its y, set the inhand_cash to 0, which will terminate the while loop
                    cout << "Alright, thanks for playing!" << endl;
                    inhand_cash = 0;
                }
                else
                { //if its not y, it must be n, since we have the other if statement.
                    cout << "Cool, let's continue!" << endl;
                }
            }
        }
    }
}
