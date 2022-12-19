#include "State.h"
#include <fstream>
//#include "Notification.h"
#include <iostream>
using namespace std;

/* User createUser(){
     string username;
     cout << "Type your username: ";
     cin >> username;
     string pw;
     cout << "Enter your password: ";
     cin >> pw;
     User *user = new User(username, pw);

     return *user;
 }

 void createNewPost( User newUser){
     bool askToCreatePost;
     cout <<"Do you want to create a new post? (1 for yes 0 for no):";
     cin >> askToCreatePost;

     if (askToCreatePost)
     {
         string description;
         cout << "Enter description of the product: ";
         cin >> description;
         string category;
         cout << "Enter category of the product: ";
         cin >> category;
         float price;
         cout << "Enter price of the product: ";
         cin >> price;
         bool share;
         cout << "Are you sharing the product? (enter 1 for yes and 0 for no): ";
         cin >> share;

      newUser.createPost(description, category, price, share);
      cout << newUser.getPostHistory()[0]->getDescription() << endl;

      createNewPost(newUser);
    }
    else {
        bool askToExit;
        cout <<"Do you want to exit the app? (1 for yes 0 for no):";
     cin >> askToExit;
     if (askToExit){
         exit(1);
     }
     bool askToSearch;
     cout <<"Do you want to search for a post? (1 for yes 0 for no):";
     cin >> askToSearch;
     if (askToSearch){
         int numPost;
         numPost = newUser.numOfPosts;
         for (int i = 0; i < numPost; i++)
         {
             cout << newUser.searchIsShare()[i].getDescription() << endl;
         }
     }
     else {
         exit(1);
     }

    }

 }


 void navigation(){
     bool askToExit;
     cout <<"Do you want to exit the app? (1 for yes 0 for no):";
     cin >> askToExit;
     if (askToExit){
         exit(1);
     }
    bool askToCreateUser;
    cout <<"Create a user accout? (1 for yes 0 for no):";
    cin >> askToCreateUser;
     if (askToCreateUser){
         createNewPost( createUser());
     }


     navigation();

 }*/

/*void createNewPost(User &newUser){
     bool askToExit;
    cout <<"Do you want to exit the app? (1 for yes 0 for no):";
    cin >> askToExit;
    if (askToExit){
        exit(1);
    }
    bool askToCreatePost;
    cout <<"Do you want to create a new post? (1 for yes 0 for no):";
    cin >> askToCreatePost;

    if (askToCreatePost)
    {
        string description;
        cout << "Enter description of the product: ";
        cin >> description;
        string category;
        cout << "Enter category of the product: ";
        cin >> category;
        float price;
        cout << "Enter price of the product: ";
        cin >> price;
        bool share;
        cout << "Are you sharing the product? (enter 1 for yes and 0 for no): ";
        cin >> share;
        newUser.createPost(description, category, price, share);
        createNewPost(newUser);

void createNewPost(User &newUser)
{
   bool askToExit;
   cout << "Do you want to exit the app? (1 for yes 0 for no):";
   cin >> askToExit;
   if (askToExit)
   {
       exit(1);
   }
   bool askToCreatePost;
   cout << "Do you want to create a new post? (1 for yes 0 for no):";
   cin >> askToCreatePost;

   if (askToCreatePost)
   {
       string description;
       cout << "Enter description of the product: ";
       cin >> description;
       string category;
       cout << "Enter category of the product: ";
       cin >> category;
       float price;
       cout << "Enter price of the product: ";
       cin >> price;
       bool share;
       cout << "Are you sharing the product? (enter 1 for yes and 0 for no): ";
       cin >> share;
       newUser.createPost(description, category, price, share);
       createNewPost(newUser);
   }
   else
   {
       bool seeHistory;
       cout << "Do you want to see your entire post history? (1 for yes 0 for no)";
       cin >> seeHistory;
       if (seeHistory)
       {

           for (int i = 0; i < newUser.numOfPosts; ++i)
           {
               cout << "Post " << (i + 1) << " is about: " << newUser.getPostHistory()[i]->getDescription() << endl;
               cout << "Category is: " << newUser.getPostHistory()[i]->getCategory() << endl;
               cout << "Price is: " << newUser.getPostHistory()[i]->getPrice() << endl;
               if (newUser.getPostHistory()[i]->getIsShare())
               {
                   cout << "Share" << endl;
               }
               else
               {
                   cout << "ISO" << endl;
               }
           }
           createNewPost(newUser);
       }
   }*/

/* else
 {
     bool searchPost;
     cout << "Do you want to filter the posts? (enter 1 for Share)";
     cin >> searchPost;
     if (searchPost)
     {
         Post *sharingPost = newUser.searchIsShare();
         for (int i = 0; i < newUser.numOfPosts; i++)
         {
             if (sharingPost[i].getDescription() != "0")
             {
                 cout << "Post " << (i + 1) << " is about: " << sharingPost[i].getDescription() << endl;
                 cout << "Category is: " << sharingPost[i].getCategory() << endl;
                 cout << "Price is: " << sharingPost[i].getPrice() << endl;
                 if (sharingPost[i].getIsShare())
                 {
                     cout << "Share" << endl;
                 }
                 else
                 {
                     cout << "ISO" << endl;
                 }
             }
         }

         createNewPost(newUser);
     }

     createNewPost(newUser);
 }
}
}*/

int main()
{
    //ifstream fs1("State.txt");
    //State s1(fs1);
   // cout << s1.getUserHistory()[0]->getPostHistory()[0]->getNumOfNotifications() << endl;
    //cout << s1.getUserHistory()[0]->getUsername() <<endl;
   //createPost(fs1, 1, "iPad", "electronics", 450, 0);
    //createPost(fs1, 1, "Calculator", "electronics", 500, 1);
    //createPost(fs1, 0, "Gaming_mouse", "electronics", 500, 0);
    //createNotification(fs1, 0, 1, 0, "Can you selle it to me, Gian?");
    //createNotification(fs1, 0, 2, 0, "Can you selle it to me, Gian?");
    //searchIsShare(fs1);
    //createUser(fs1, "gurung2", "123456");
    /*State s1;
    s1.createNewUser("gurung2", "123456");
    s1.createNewUser("Cole", "sdMyLove");
    s1.createNewUser("Intisar", "whynot");
    s1.getUserHistory()[0]->createPost("laptop", "electronics", 450, 1);
    s1.getUserHistory()[0]->createPost("ipod", "electronics", 100, 0);
    s1.getUserHistory()[2]->createPost("backpack", "stationaries", 50, 0);
    s1.getUserHistory()[0]->getPostHistory()[0]->createNotification(s1.getUserHistory()[2]->getUserIndex(), "Your professor wants it <3.");
    s1.getUserHistory()[0]->getPostHistory()[0]->createNotification(s1.getUserHistory()[2]->getUserIndex(), "Hi, it's inti. I wanna buy it.");
    s1.getUserHistory()[0]->getPostHistory()[1]->createNotification(s1.getUserHistory()[1]->getUserIndex(), "Your professor doesn't want it.");*/


    //User u1("gurung2", "123456");
    // createNewPost(u1);
    //User u2("Cole", "sdMyLove");
    //User u3("Intisar", "whynot");

    //u1.createPost("laptop", "electronics", 450, 1);
    //u1.createPost("ipod", "electronics", 100, 0);
    //u3.createPost("backpack", "stationaries", 50, 0);

    //u1.getPostHistory()[0]->createNotification(&u3, "Your professor wants it <3.");
    //u1.getPostHistory()[0]->createNotification(&u3, "Hi it's inti. I wanna buy it.");
    //u1.getPostHistory()[1]->createNotification(&u2, "Your professor doesn't want it!!");
    //  cout << u1.getPostHistory()[0]->getNotificationHistory()[0]->getMessage() << endl;

    // constructor using files
    // ifstream fs("State.txt");
    // User u3(fs);
    // cout << u3.getPassword() << endl;
    // cout << u3.getPostHistory()[0]->getCategory() << endl;

    /*ofstream fs("State.txt");
    for (int i = 0; i < s1.getNumOfUsers(); i++)
    {
        s1.getUserHistory()[i]->write_to(fs);
    }*/
    
    //u1.write_to(fs);
    //u2.write_to(fs);
    //u3.write_to(fs);

   // User u5 = u1;


    /*cout << u1.getPassword() << endl;
    Post(string d, string c, float p, bool s, int nr, User postC)
    Post p1("iphone", "electronics", 250, false, u1);
    cout << p1.getCreator() << endl;
    u1.setRecentPost(&p1);
    cout << u1.getRecentPost().getDescription() <<endl;

    cout << u1.getRecentPost().getCategory() << endl;
    User u2; // default
    cout << u2.numOfPosts << endl;
    u2.createPost("Fan", "Electronics", 100, true);
    u2.createPost("Chair", "furniture", 120, false);
    cout << u2.getRecentPost().getCategory() << endl;
    u2.createPost("lamp", "electronics", 50, true);
    cout << u2.getRecentPost().getCategory() << endl;
    cout << u2.getPost(2).getDescription() << endl;
    Post *sharingPost = u2.searchIsShare();
    cout << sharingPost[0].getCategory() << endl;
    cout << sharingPost[1].getCategory() << endl;
    cout << u2.getPostHistory() << endl;
    cout << u2.numOfPosts << endl;
    cout << u2.getRecentPost().getCategory() << endl;
    u2.createNotification(&u1, "I need this");
    u2.createNotification(&u1, "This looks interesting");
    cout << u2.getRecentNotification().getMessage() << endl;
    cout << u2.getNotificationHistory()[0]->getMessage() << endl;*/
}