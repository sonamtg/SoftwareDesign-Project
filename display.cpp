#include "State.h"
#include <fstream>
#include <iostream>
#include"/usr/local/cs/cs251/react.h"
using namespace std;
class Post;
// class Notification;
void State::callMainDisplay(int pn){
    if (getPageNumber() == 2){
        displayHome();
    }
    
}
void display(const State &state){
   switch (state.displayNum)
   {
   
   case 0:
    break;
   
   case 1:
    _add_yaml("sign_up.yaml", {{"logo_index", 0}, {"username_index", 11}, {"username_input_index", 31}, {"password_index", 21}, {"password_input_index", 51}});
    break;
    
   default:
       break;
   }
}

void State::displayHome(){
for (int i = 0; i < getNumOfUsers(); i++)
{
    _add_yaml("home_page.yaml", {{"logo_index", 0}, {"post_array_index", 10}});

    /*for (int j = 0; j < getUserHistory()[i]->numOfPosts; j++)
    {
        cout << getUserHistory()[i]->getPostHistory()[j]->getDescription() << endl;
        cout << getUserHistory()[i]->getPostHistory()[j]->getCategory() << endl;
        cout << getUserHistory()[i]->getPostHistory()[j]->getPrice() << endl;
        cout << getUserHistory()[i]->getPostHistory()[j]->getIsShare() << endl;

        }
    }*/
    }
}
 void displayLogIn(const State &state){
     _add_yaml("login.yaml", {{"logo_index", 0}, {"username_index", 11}, {"username_input_index", 31}, {"password_index", 21}, {"password_input_index", 51}});
     
 }

 void displaySignUp(const State &state){
     _add_yaml("sign_up.yaml", {{"logo_index", 0}, {"username_index", 10}, {"signUp_message_index", 0}, {"username_input_index", 30}, {"password_index", 19}, {"password_input_index", 51}}); 
     
     }

/*if (state2.getPageNumber() == 2){
    displayHome();
}*/

void State::search(){

         int search_num;
          cout << "0(Description), 1(Is Share), 2(ISO)";
          cin >> search_num;

          if (search_num == 0)
          {
            int size = 0;
            string kw;
            cout << "enter the description" << endl;
            cin >> kw;
            for (int i = 0; i < getNumOfUsers(); i++)
                {

                Post *array = getUserHistory()[i]->searchDescription(kw, size);
                for (int j = 0; j < size; j++){
                    cout << array[j].getDescription() << endl;
                    cout << array[j].getCategory() << endl;
                    cout << array[j].getPrice() << endl;
                    cout << array[j].getIsShare() << endl;

                }

            }

          }
          

          else if (search_num == 1){

            for (int i = 0; i < getNumOfUsers(); i++)
                {

                Post *array = getUserHistory()[i]->searchIsShare();
                int size = getUserHistory()[i]->getNumSharing();
                for (int j = 0; j < size; j++){
                    cout << array[j].getDescription() << endl;
                    cout << array[j].getCategory() << endl;
                    cout << array[j].getPrice() << endl;
                    cout << "Share" << endl;

                }

            }
          }
          else if (search_num == 2){

            for (int i = 0; i < getNumOfUsers(); i++)
                {

                Post *array = getUserHistory()[i]->searchIsISO();
                int size = getUserHistory()[i]->getNumISO();
                for (int j = 0; j < size; j++){
                    cout << array[j].getDescription() << endl;
                    cout << array[j].getCategory() << endl;
                    cout << array[j].getPrice() << endl;
                    cout << "ISO" << endl;

                }

            }
        }
}

void State::postIndexFinder(int &userIndx, int &postIndx) {
    int size = 0;

        for (int i = 0; i < numOfUsers; i++)
        {
            for (int j = 0; j < userHistory[i]->numOfPosts; j++)
            {
                size++;
                // cout << "Size: " << size << endl;
            }
        }
        int doublesize = size * 2;

        int postShowArray[doublesize];

        int repeater = 0;

        for (int i = 0; i < numOfUsers; i++)
        {
            for (int j = 0; j < userHistory[i]->numOfPosts; j++)
            {
                postShowArray[repeater] = i; // ith user
                repeater++;
                // cout << "repeater:" << repeater << endl;
                // cout << i << endl;
                postShowArray[repeater] = j; // jth post
                repeater++;
                // cout << "repeater:" << repeater << endl;
                // cout << j << endl;
            }
        }

        string s;
        string message;
        for (int i = 0; i < 20; i++)
        {
            s = _global_mem[355+i];
            if (s != "~")
            {
                message.append(s);  
            }
        
        }
        int choice = stoi(message) +1;

        userIndx = postShowArray[(choice * 2) - 2];
        postIndx = postShowArray[(choice * 2) - 1];
}

int *State::stateSearchDescription(int &newSize){
    string s, message;
    string keyword;
    int size = 0;
    int repeater = 0;
    int realIndex = 0;
    for (int i = 0; i < 50; i++) // getting the description from th global mem
            {
                s = _global_mem[89+i];
                if (s != "~")
                {
                    message.append(s);  
                }
            
            }
            keyword = message.substr(0, message.length()-1);
    for (int i = 0; i < numOfUsers; i++)
    {
        for (int j = 0; j < userHistory[i]->numOfPosts; j++)
        {
            if (userHistory[i]->getPostHistory()[j]->getDescription() == keyword)
            {
                size++;
                
            }
            
            
        }
        
    }
    newSize = size;
    int *indxarr = new int[size];
    for (int i = 0; i < numOfUsers; i++)
    {
        for (int j = 0; j < userHistory[i]->numOfPosts; j++)
        {
            if (userHistory[i]->getPostHistory()[j]->getDescription() == keyword)
            {
                indxarr[repeater] = realIndex;
                repeater++;
        
            }
            realIndex++;
        }
        
    }
    return indxarr;
    
}

int *State::offsetForNotification(int &newsize, int currentUser){
    int num = 0; 
    int repeater = 0;

    for (int i = 0; i < userHistory[currentUser]->numOfPosts; i++)
    {
        for (int j = 0; j < userHistory[currentUser]->getPostHistory()[i]->numOfNotifications; j++)
        {
            newsize++;
            
        }
    }
    int *notificationArray = new int[newsize*3];
    
    
    for (int i = 0; i < currentUser; i++)
    {
        num += 6; //user~\n
        num += userHistory[i]->getUsername().length() + 2;
        num += userHistory[i]->getPassword().length() + 2;
        for (int j = 0; j < userHistory[i]->numOfPosts; j++)
        {
            num += 6;  //post~\n
            num += userHistory[i]->getPostHistory()[j]->getDescription().length()+2;
            num += userHistory[i]->getPostHistory()[j]->getCategory().length()+2;
            num += to_string((int)userHistory[i]->getPostHistory()[j]->getPrice()).length()+2;
            num += 3;
            num += to_string(userHistory[i]->getPostHistory()[j]->getPostIndex()).length()+2;
            for (int k = 0; k < userHistory[i]->getPostHistory()[j]->numOfNotifications; k++)
            {
                num += 14;  // notification~\n
                num += userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getMessage().length()+2;
                num += to_string(userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getUserFrom()).length()+2;
                num += to_string(userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getUserTo()).length()+2;
                
            }
            
            
        }
        

    }
    num += 6; // current user~\n
    num += userHistory[currentUser]->getUsername().length()+2;
    num += userHistory[currentUser]->getPassword().length()+2;
    for (int i = 0; i < userHistory[currentUser]->numOfPosts; i++)
    {
        //cout << " post " << num << endl;
        num += 6; //post~\n
        //cout << " des " << num << endl;
        num += userHistory[currentUser]->getPostHistory()[i]->getDescription().length()+2;
        //cout << " cat " << num << endl;
        num += userHistory[currentUser]->getPostHistory()[i]->getCategory().length()+2;
        //cout << " price " << num << endl;
        num += to_string((int)userHistory[currentUser]->getPostHistory()[i]->getPrice()).length()+2;
        //cout << " share " << num << endl;
        num += 3;
        //cout << " postIndex " << num << endl;
        num += to_string(userHistory[currentUser]->getPostHistory()[i]->getPostIndex()).length()+2;
        for (int j = 0; j < userHistory[currentUser]->getPostHistory()[i]->numOfNotifications; j++)
        {
            //cout << " notification " << num << endl;
            num += 14; //notification~\n
            //cout << " message " << num << endl;
            notificationArray[repeater] = num +1;
            repeater++;
            num += userHistory[currentUser]->getPostHistory()[i]->getNotificationHistory()[j]->getMessage().length()+2;
            //cout << " fromIndex " << num << endl;
            notificationArray[repeater] = num +1;
            repeater++;
            num += to_string(userHistory[currentUser]->getPostHistory()[i]->getNotificationHistory()[j]->getUserFrom()).length()+2;
            //cout << " toIndex " << num << endl;
            notificationArray[repeater] = num +1;
            repeater++;
            num += to_string(userHistory[currentUser]->getPostHistory()[i]->getNotificationHistory()[j]->getUserTo()).length()+2;
            
        }
        

    }
    
    
return notificationArray;
    
}