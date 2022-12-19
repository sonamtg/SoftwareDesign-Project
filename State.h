#ifndef __STATE_H__
#define __STATE_H__
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Post.h"
using namespace std;

class Post;

class State
{
    int numOfUsers;
    User **userHistory;
    User *recentUser;
    int pageNumber;
    int currentUserIndex;
    int realTimeIndex;

public:
    string input_username;
    string input_password;
    State(istream &is);
    State();
    static const int offset;
    int displayNum; 
    string readWholeThing(istream & is);
    void createNewUser(string uname, string pw);
    User **getUserHistory();
    int getNumOfUsers();
    int getPageNumber();
    void setPageNumber(int pageNum);
    int getCurrentUserIndex();
    void setCurrentUserIndex(int currentUIndex);
    int userLoop(istream &is);
    int postLoop(istream &is, User *u, string kw);
    // int notificationLoop(istream &is);
    User **updateStorage();
    int StateLoop(istream &is);
    void updateSignUp();
    //void displayHome();
    void updateHome();
    int userExist(string username, string pw);
    void writeTo(ostream &os);
    void displayHome();
    void displayLogIn();
    void displaySignUp();
    void search();
    void stateCreatePost(int currentUserIndex);
    void makeRequest(int senderIndex);
    void callMainDisplay(int postnum);
    void update();
    void handle_button_event(int button);
    int offset_for_num_users() const;
    int *offset_for_posts(int &num_post);
    void postIndexFinder(int &userIndx, int &postIndx);
    int *stateSearchDescription(int &newSize);
    int *offsetForNotification(int &newsize, int currentUser);
    ~State();

};
void display(const State &state);

#endif