#include <iostream>
#include <fstream>
using namespace std;
#include "State.h"

// not using the function anymore
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
    ifstream fs("curr_state");
    State state2(fs); // this state is created to write in to the current state
    bool just_starting;
    int currentUserIndex;
    // this has to be a user input
    string username, pw;
    int userExistInt = state2.userExist(username, pw);
    if (userExistInt == -1)
    {
      just_starting = true; 
      state2.updateSignUp();
      ofstream of("curr_state");
      state2.writeTo(of);
      cout << state2.getNumOfUsers() << endl;
      currentUserIndex = state2.getNumOfUsers() - 1; 
    }
    else {
      just_starting = false;
      currentUserIndex = userExistInt;
    }

    while (true)
    {
        int input;
        //if (!just_starting){
        //if (!getline(cin, input)) break;
        //if ("q" == input) break;
        //}
        //if (just_starting) fs2.open("initial_state");
        //fs.open("curr_state");
       // State state2(fs2);
       // fs2.close();
        //mainLoop(state2);
        cout << "0 -> Exit, 1 -> Home Page, 2 -> Search Post, 3 -> Create Post, 4 -> Make a request";
        cin >> input;
        if (input == 0){
          break;
        }
        else if (input == 1)
        {
           state2.displayHome();
        }
      
        else if (input == 2){
          state2.search();
        }  


        else if (input == 3){

          state2.stateCreatePost(currentUserIndex);
    }

    else if (input == 4)
    {
      state2.makeRequest(currentUserIndex);
    }

    else {
      cout << "Wrong input!!!" << endl;
    }
    

    just_starting = false;
        
  }
    
    
}

int main() {
  _main_loop_early_draft();
}
