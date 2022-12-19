#include "User.h"
#include "Post.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Post;

User::User()
{
    password = "0";
    username = "0";
    numOfPosts = 0;
    postHistory = 0;
    // recentPost = 0; // this should call the default constructor
}
User::User(string u, string p)
{
    username = u;
    password = p;
    numOfPosts = 0;
    postHistory = 0;
    // recentPost = 0; // this should call the default constructor
}
User::User(istream &is)
{
    string keyword;
    is >> keyword;
    is.get();
    if (keyword != "User")
    {
        cerr << "Error in User constructor!" << endl;
    }
    else
    {
        is >> username;
        is.get();
        is >> password;
        is.get();
    }
    numOfPosts = 0;
    postHistory = 0;
    // recentPost = 0;
}

string User::getUsername() const
{
    return username;
}
string User::getPassword() const
{
    return password;
}
int User::getUserIndex() const
{
    return userIndex;
}

void User::setUserIndex(int i)
{
    userIndex = i;
}

// might need it
/*Post User::getRecentPost() const
{
    if (recentPost == 0)
    {
        cout << "You have not created any post yet" << endl;  code
        return Post();
    }
    else
    {
        return *recentPost;
    }
} */

/*void User::setRecentPost(Post *p)
{ // not necessary rn
    recentPost = p;
}*/
void User::createPost(string des, string cat, float pr, bool shr)
{
    Post *newPost = new Post(numOfPosts, des, cat, pr, shr, this); // this has to be dynamic
    // recentPost = newPost;                               // recentPost pointer points to the latest post made by the user
    numOfPosts++; // update the num of posts made by the user
    if (numOfPosts < 2)
    {
        postHistory = new Post *[numOfPosts];
        postHistory[0] = newPost;
    }
    else
    {
        postHistory = updateStorage();
        postHistory[numOfPosts - 1] = newPost;
    }
}

Post **User::getPostHistory()
{

    return postHistory;
}

Post **User::updateStorage()
{
    Post **updatedPostHistory = new Post *[numOfPosts]; // create a new pointer with the appropriate array size
    for (int i = 0; i < numOfPosts - 1; ++i)
    {
        // cout << "post reassigned" << endl;
        updatedPostHistory[i] = postHistory[i]; // copy all the pointers to posts except the last one
    }
    delete[] postHistory;
    return updatedPostHistory;
}

Post User::getPost(int n) const
{
    if (n < numOfPosts)
    {
        return *postHistory[n];
    }
    else
    {
        cout << "Post you are trying to access does not exist." << endl;
        return Post();
    }
}

int User::getNumSharing(){
    
    int count = 0; // to maintain the order of supplyPostList
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == true)
        {
            count++; // finding the right size of the new array to be created
        }
    }
    return count;
}

int User::getNumISO(){
    
    int count = 0; // to maintain the order of supplyPostList
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == false)
        {
            count++; // finding the right size of the new array to be created
        }
    }
    return count;
}


Post *User::searchIsShare() const
{
    int count = 0; // to maintain the order of supplyPostList
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == true)
        {
            count++; // finding the right size of the new array to be created
        }
    }

    Post *supplyPostList = new Post[count]; // creating the array with right size
    count = 0;                              // resetting the value of count to start filling in the array from the start of the array

    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == true)
        {
            supplyPostList[count] = *postHistory[i];
            count++;
        }
    }

    return supplyPostList;
}

Post *User::searchIsISO() const
{

    int count = 0; // to maintain the order of demandPostList
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == false)
        {
            count++;
        }
    }

    Post *demandPostList = new Post[count]; // creating the right sized array of posts
    count = 0;                              // resetting the value to start filling up the array from thr start
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getIsShare() == false)
        {
            demandPostList[count] = *postHistory[i];
            count++;
        }
    }
    return demandPostList;
}

Post *User::searchDescription(string keyWord, int &size) const
{

    int count = 0; // to maintain the order of demandPostList
    for (int i = 0; i < numOfPosts; i++)
    {
        if (postHistory[i]->getDescription() == keyWord)
        {
            count++;
        }
    }
    size = count;

    if (count > 0)
    {
        Post *descriptionPostList = new Post[count]; // creating the right sized array of posts
        count = 0;                                   // resetting the value to start filling up the array from thr start
        for (int i = 0; i < numOfPosts; i++)
        {
            if (postHistory[i]->getDescription() == keyWord)
            {
                descriptionPostList[count] = *postHistory[i];
                count++;
            }
        }
        return descriptionPostList;
    }
    else
    {
        cout << "There is no post with that description" << endl;
        return 0;
    }
}

/*User &User::operator=(const User &u){
    password = u.password;
    username = u.username;

    for (int i = 0; i < u.numOfPosts; ++i){
        createPost(u.postHistory[i]->getDescription(), u.postHistory[i]->getCategory(), u.postHistory[i]->getPrice(), u.postHistory[i]->getIsShare());
    }
    return *this;

}*/

void User::write_to(ostream &os) const{
    if (username == "0")
    {
        cerr << "No valid user" << endl;
    }
    else
    {
        os << "User" << '~' << endl;
        os << username << '~' << endl;
        os << password << '~' << endl;
        if (numOfPosts == 0)
        {
            cout << "No posts created" << endl;
        }
        else
        {
            for (int i = 0; i < numOfPosts; ++i)
            {
                os << "Post" << '~' << endl;
                os << postHistory[i]->getDescription() << '~' << endl;
                os << postHistory[i]->getCategory() << '~' << endl;
                os << postHistory[i]->getPrice() << '~' << endl;
                os << postHistory[i]->getIsShare() << '~' << endl;
                os << postHistory[i]->getPostIndex() << '~' << endl;
                // os << postHistory[i]->numOfNotifications() << endl;

                if (postHistory[i]->getNumOfNotifications() == 0)
                {
                    cout << "No notification created" << endl;
                }

                else
                {
                    for (int j = 0; j < postHistory[i]->getNumOfNotifications(); ++j)
                    {
                        os << "Notification" << '~' << endl;
                        os << postHistory[i]->getNotificationHistory()[j]->getMessage() << '~' << endl;
                        os << postHistory[i]->getNotificationHistory()[j]->getUserFrom() << '~' << endl; // this gives the username of the sender
                        os << postHistory[i]->getNotificationHistory()[j]->getUserTo() << '~' << endl;   // this gives the username of the receiver
                    }
                }
            }
        }
    }
}
int User::size_in_bytes() const {
    ostringstream oss;
    write_to(oss);
    return oss.str().length();
}

User::~User()
{
    for (int i = 0; i < numOfPosts; ++i)
    {

        delete postHistory[i]; // deletes individual posts
        cout << "Post deleted" << endl;
    }
    delete[] postHistory; // deletes the array of pointers that points to an array of pointers to a post
}

