#include <iostream>
#include "Post.h"
#include "User.h"
#include <fstream>
using namespace std;

// constructor - later
Post ::Post(int index, string d, string c, float p, bool s, User *postC)
{
    description = d;
    category = c;
    price = p;
    isShare = s;
    numRequests = 0;
    creatorPointer = postC;
    postCreator = postC->getUsername();
    // postC.setRecentPost(this);
    numOfNotifications = 0;
    postIndex = index;

}
Post ::Post()
// default constructor
{
    description = "0";
    category = "0";
    price = 0;
    isShare = 0;
    numRequests = 0;
    postCreator = "0";
    numOfNotifications = 0;
    creatorPointer = 0;
    postIndex=0; //if we ever call the default constructor for the post class which we won't
}

Post::Post(istream &is){
    string keyword;
    is >> keyword;
    is.get(); 
    if (keyword != "Post") {
        cerr << "Error in Post constructor!" << endl;
    }
    else{
        is >> description;
        is.get();
        is >> category;
        is.get();
        is >> price;
        is.get();   
        is >> isShare;
        is.get(); 
    }
    numRequests = 0;
    postCreator = "0";
    numOfNotifications = 0;
    creatorPointer = 0;
}

void Post::setDescription(string d)
{
    description = d;
}

void Post::setCategory(string c)
{
    category = c;
}
void Post::setPrice(int p)
{
    price = p;
}
void Post::setShare(bool v)
{
    isShare = v;
}
void Post::setPostCreator(User *postC)
{
    postCreator = postC->getUsername();
}

// creating the getters for the member variables as they are all going to be private

string Post::getDescription()
{
    return description;
}

string Post::getCategory()
{
    return category;
}
float Post::getPrice()
{
    return price;
}
int Post::getNumRequest()
{
    return numRequests;
}
string Post::getCreator()
{
    return postCreator;
}
bool Post::getIsShare() const
{
    return isShare;
}
User *Post::getCreatorPointer(){
    return creatorPointer;
}

int Post::getNumOfNotifications() const {
    return numOfNotifications;
}
void Post::setPostIndex(int index){
    postIndex=index;
}
int Post::getPostIndex(){
    return postIndex;
}
void Post::createNotification(int userFrom, string mess){
    Notification* newNotification = new Notification(userFrom, creatorPointer->getUserIndex(), mess);
    //recentNotification = newNotification;
    numOfNotifications++;
    if (numOfNotifications < 2)
    {
        notificationHistory = new Notification *[numOfNotifications];
        notificationHistory[0] = newNotification;
    }
    else {
        notificationHistory = updateNotificationStorage();
        notificationHistory[numOfNotifications - 1] = newNotification;
    }
    
} 
/*Notification Post::getRecentNotification() const {
    return *recentNotification;
}*/

Notification **Post::getNotificationHistory(){
    return notificationHistory;
}

Notification **Post::updateNotificationStorage(){
    Notification **updatedNotificationHistory = new Notification *[numOfNotifications]; // create a new pointer with the appropriate array size
    for (int i = 0; i < numOfNotifications - 1; ++i)
    {
        cout << "notifications reassigned" << endl;
        updatedNotificationHistory[i] = notificationHistory[i]; // copy all the pointers to posts except the last one
    }
    delete[] notificationHistory;
    return updatedNotificationHistory;
}

Post::~Post(){
    for (int i = 0; i < numOfNotifications; ++i){
        
        delete notificationHistory[i];
        cout << "Notification deleted" << endl;
    }
    delete [] notificationHistory;
    
}

