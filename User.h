#ifndef __USER_H__
#define __USER_H__
//#include "Notification.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Post;

class User
{
    string password;
    Post **postHistory;
    int userIndex;
    // Notification **notificationHistory;
    // Post *recentPost; // this points to the most recent post created by this user
    // Notification *recentNotification; // this points to the most recent notification recieved by this user
public:
    int numOfPosts;
    // int numOfNotifications;
    string username;
    // this calls the default constructor
    User();
    User(string u, string p);
    User(istream &is); // constructor to read in from a text file

    // void printData();
    string getUsername() const;
    string getPassword() const;
    void setRecentPost(const Post *p);
    void updateStorage(int newNumPost);
    void setUserIndex(int i);
    int getUserIndex() const;
    int getNumSharing();
    int getNumISO();

    void createPost(string des, string cat, float pr, bool shr);
    Post **updateStorage();
    Post **getPostHistory();
    Post getPost(int n) const;
    Post *searchIsShare() const;
    Post *searchIsISO() const;
    Post *searchDescription(string keyWord, int &size) const;
    // User &operator=(const User &u); // assignment operator

    void write_to(ostream &os) const;
    ~User(); // destructor

    int size_in_bytes() const;
};

#endif
