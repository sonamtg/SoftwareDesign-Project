#ifndef __POST_H__
#define __POST_H__
#include "User.h"
#include "Notification.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Post
{
    string description; // the description about the item of the post
    string category;    // the type of category of the item
    float price;        // stores the price of the item
    bool isShare;       // sharing or not
    string postCreator;
    User *creatorPointer; 
     // Post class is going to our self-defined User and every post is going to contain a user in it
    int numRequests;
    Notification **notificationHistory;
    int postIndex;
    //Notification *recentNotification; // this points to the most recent notification recieved by this user

public:
    int numOfNotifications; 
    Post(int index, string d, string c, float p, bool s, User *postC);
    Post();
    Post(istream &is);
    void setDescription(string d);

    void setCategory(string c);
    void setPrice(int p);
    void setShare(bool v);
    void setPostCreator(User *postC);
    Notification **updateNotificationStorage();
    Notification **getNotificationHistory();
    void createNotification(int userF, string mess);
   // Notification getRecentNotification() const;

    // creating the getters for the member variables as they are all going to be private

    string getDescription();
    string getCategory();
    float getPrice();
    int getNumRequest();
    int getNumOfNotifications() const;
    string getCreator();
    bool getIsShare() const;
    User *getCreatorPointer();
    void setPostIndex(int index);
    int getPostIndex();
    ~Post();
};

#endif