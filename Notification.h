#ifndef __NOTIFICATION_H__
#define __NOTIFICATION_H__
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#include "Post.h"

class User;

class Notification{
    string message;
    int userFrom;
    int userTo;

public:
    Notification(); //Default constructor
    Notification(int userF, int userT, string m); //Constructor with user input
    Notification(istream &is);

    string getMessage()const;
    int getUserFrom() const;
    int getUserTo() const;
    void setUserFrom(int uf);
    void setUserTo(int ut);


};

#endif
