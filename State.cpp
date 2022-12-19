#include <iostream>
#include <string>
#include "State.h"
#include "User.h"
#include "Post.h"
#include"/usr/local/cs/cs251/react.h"

#include <fstream>
using namespace std;

class Post;

const int State::offset = 31;

State::State()
{
    numOfUsers = 0;
    userHistory = 0;
}

State::State(istream &is)
{
    numOfUsers = 0;
    userHistory = 0;
    currentUserIndex = 0;
    StateLoop(is);
}

int State::StateLoop(istream &is)
{
    string keyword;
    getline(is, keyword, '~');
    is.get();
    if (is.eof())
    {
        cout << "The file ended." << endl;
        return -1;
    }
    else if (keyword == "User")
    {
        string userName;
        string password;
        getline(is, userName, '~');
        is.get();
        getline(is, password, '~');
        is.get();
        createNewUser(userName, password);
        //cout << "New user created." << endl;
        StateLoop(is);
    }
    else if (keyword == "Post")
        {
        
            string description;
            getline(is, description, '~');
            is.get();
            string category;
            getline(is, category, '~');
            is.get();
            string stringPrice;
            float price;
            getline(is, stringPrice, '~');
            price = stof(stringPrice);
            is.get();
            string stringIsShare;
            bool isShare;
            getline(is, stringIsShare, '~');
            isShare = stoi(stringIsShare);
            is.get();
            string stringPostIndex;
            int postIndex;
            getline(is, stringPostIndex, '~');
            postIndex = stoi(stringPostIndex);
            is.get();
            getUserHistory()[numOfUsers - 1]->createPost(description, category, price, isShare);
            //cout << "New post created" << endl;
            StateLoop(is);
            
        }
    else if (keyword == "Notification")
            {
                string msg;
                getline(is, msg, '~');
                is.get();
                string stringUserFrom;
                int userFrom;
                getline(is, stringUserFrom, '~');
                userFrom = stoi(stringUserFrom);
                is.get();
                string stringUserTo;
                int userTo;
                getline(is, stringUserTo, '~');
                userTo = stoi(stringUserTo);
                is.get();
                getUserHistory()[numOfUsers - 1]->getPostHistory()[(getUserHistory()[numOfUsers - 1]->numOfPosts) - 1]->createNotification(userFrom, msg);
                StateLoop(is);
                
            }

    }

User **State::getUserHistory()
{
    return userHistory;
}

int State::getNumOfUsers()
{
    return numOfUsers;
}

int State::getPageNumber(){
    return pageNumber;
}

void State::setPageNumber(int pageNum){
    pageNumber = pageNum;
}

int State::getCurrentUserIndex(){
    return currentUserIndex;
}
void State::setCurrentUserIndex(int currentUIndex){
    currentUserIndex = currentUIndex;

}
int State::offset_for_num_users() const{
    int num_user_offset = 0;
    for (int i = 0; i < numOfUsers; i++){
        num_user_offset += userHistory[i]->size_in_bytes();
    }
    return 74 + num_user_offset;

}
  
int State::userExist(string username, string pw){
    cout << username << " " << pw << endl;
    //username //.append(pw);
    //cout << username << endl;
    int lenUs = username.length() -1 , lenPs = pw.length() - 1;

    for (int i = 0; i < numOfUsers; i++)
    {

        if (getUserHistory()[i]->getUsername() == username.substr(0, lenUs) && getUserHistory()[i]->getPassword() == pw.substr(0, lenPs)){
            cout << "i = " << i << endl;
            return i;
        }
        
    }
    return -1;
    
}

int *State::offset_for_posts(int &num_post){
    int size = 0;
    for (int i = 0; i < numOfUsers; i++){
        size += userHistory[i]->numOfPosts;    
    }
    num_post = size;
    int *post_indices = new int[size*4];
    int index = 0;
    int arr_idx = 0;
    for (int i = 0; i < numOfUsers; i++){
        index += 6; //User~\n
        index += userHistory[i]->getUsername().length();
        index += 2;
        index += userHistory[i]->getPassword().length();
        index += 2;
        for (int j = 0; j < userHistory[i]->numOfPosts; j++){
            index += 6; //Post~\n
            post_indices[arr_idx] = index +1;
            arr_idx++;
            index += userHistory[i]->getPostHistory()[j]->getDescription().length();
            //cout << "des : " << userHistory[i]->getPostHistory()[j]->getDescription().length() << endl;
            index += 2;
            post_indices[arr_idx] = index +1;
            arr_idx++;
            index += userHistory[i]->getPostHistory()[j]->getCategory().length();
            //cout << "cat : " << userHistory[i]->getPostHistory()[j]->getCategory().length() << endl;
            index += 2;
            post_indices[arr_idx] = index +1;
            arr_idx++;
            string price_str = to_string( (int)userHistory[i]->getPostHistory()[j]->getPrice());
            index += price_str.length(); 
            //cout << price_str;
            //cout << "prc : " << price_str.length() << endl;
            index += 2;
            post_indices[arr_idx] = index +1;
            arr_idx++;
            index += 3; // isShare
            string u_idx_str = to_string( userHistory[i]->getPostHistory()[j]->getPostIndex());
            index += u_idx_str.length();
            //cout << "index : " << u_idx_str.length() << endl;
            index += 2; // index
            for (int k = 0; k < userHistory[i]->getPostHistory()[j]->getNumOfNotifications(); k++){
                index += 14; //Notification~\n
                index +=  userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getMessage().length();
                index += 2;
                string u_from_str = to_string(userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getUserFrom());
                index += u_from_str.length();
                index += 2;
                string u_to_str = to_string(userHistory[i]->getPostHistory()[j]->getNotificationHistory()[k]->getUserTo());
                index += u_to_str.length();
                index += 2;

            }
        }

    }
    return post_indices;

}

void State::writeTo(ostream &os){
    for (int i = 0; i < numOfUsers; i++)
    {
        userHistory[i]->write_to(os);
    }
}

State::~State(){
    for (int i = 0; i < numOfUsers; i++){
        delete userHistory[i];
    }
   // delete[] userHistory;
}
