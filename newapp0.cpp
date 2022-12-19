#include <iostream>
#include <fstream>
using namespace std;
#include "State.h"

void mainLoop(State &mainState)
{
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
}

void _main_loop_early_draft() {
    ifstream fs("initial_state");
    State state(fs);
    bool just_starting;
    int currentUserIndex;
    int userExistInt = state.userExist();
    if (userExistInt == -1)
    {
      just_starting = true; 
      state.updateSignUp();
      ofstream of("curr_state");
      state.writeTo(of);
      currentUserIndex = (state.getNumOfUsers()) - 1; 
    }
    else {
      just_starting = false;
      currentUserIndex = userExistInt;
    }

    while (true)
    {
        string input;
        //if (!just_starting){
        if (!getline(cin, input)) break;
        if ("q" == input) break;
        //}
        ifstream fs2;
        if (just_starting) fs2.open("initial_state");
        else fs2.open("curr_state");
        State state2(fs2);
        fs2.close();
        mainLoop(state2);
        
    }
    
    
}

int main() {
  _main_loop_early_draft();
}
