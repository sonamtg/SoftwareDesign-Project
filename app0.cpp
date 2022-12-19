#include "State.h"
#include <iostream>
#include <fstream>
using namespace std;

void mainLoop(State &mainState)
{
    /*State s1;
    s1.createNewUser("Intisar", "MeIsStupid");
    s1.createNewUser("Sonam", "Smart");
    s1.getUserHistory()[0]->getPostHistory()[0];*/

    /*ifstream fs("State.txt");
    State s2(fs);*/
    // cout << s2.getUserHistory()[0]->getUsername() << endl;
    // cout << s2.getUserHistory()[0]->numOfPosts << endl;
    // cout << s2.getUserHistory()[2]->numOfPosts << endl;
    // cout << s2.getNumOfUsers() << endl;
    int mainChoice;
    cout << "Enter 1 to go to home page" << endl;
    cin >> mainChoice;
   
    if (mainChoice == 1)
    {
        mainState.displayHome();
    }
    else
    {
        cout << "wrong input try again!!" << endl;
        mainLoop(mainState);
    }

    // cout << s2.getUserHistory()[1]->numOfPosts << endl;

    // cout << s2.getUserHistory()[1]->getPostHistory()[0] << endl;
}

int main()
{
    mainLoop();
}