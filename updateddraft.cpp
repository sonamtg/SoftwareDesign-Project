#include "State.h"
using namespace std;

User **State::updateStorage()
{
    User **updatedUserHistory = new User *[numOfUsers]; // create a new pointer with the appropriate array size
    for (int i = 0; i < numOfUsers - 1; ++i)
    {
        // cout << "user reassigned" << endl;
        updatedUserHistory[i] = userHistory[i]; // copy all the pointers to posts except the last one
    }
    delete[] userHistory;
    return updatedUserHistory;
}

void State::createNewUser(string uname, string pw)
{
    User *newUser = new User(uname, pw); // this has to be dynamic
    recentUser = newUser;                // recentPost pointer points to the latest post made by the user
    cout << numOfUsers << endl;
    newUser->setUserIndex(numOfUsers);
    numOfUsers++;                        // update the num of posts made by the user
    if (numOfUsers < 2)
    {
        userHistory = new User *[numOfUsers];
        userHistory[0] = recentUser;
    }
    else
    {
        userHistory = updateStorage();
        userHistory[numOfUsers - 1] = recentUser;
    }
}

void State::updateSignUp()
{
    string username, password;
    cout << "What is your username?  ";
    cin >> username;
    cout << "What is your password?  ";
    cin >> password;
    createNewUser(username, password);
    displayHome();
}

void State::updateHome()
{
    int choice;
    cout << "to exit enter 0 or to see the post enter the order of the post (i.e. 3 for 3rd post): ";
    cin >> choice;
    if (choice == 0)
    {
        exit(1);
    }
    else
    {
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

        if (choice <= size)
        {

            cout << "Description: " << userHistory[postShowArray[(choice * 2) - 2]]->getPostHistory()[postShowArray[(choice * 2) - 1]]->getDescription() << endl;
            cout << "Category: " << userHistory[postShowArray[(choice * 2) - 2]]->getPostHistory()[postShowArray[(choice * 2) - 1]]->getCategory() << endl;
            cout << "Price: " << userHistory[postShowArray[(choice * 2) - 2]]->getPostHistory()[postShowArray[(choice * 2) - 1]]->getPrice() << endl;
            cout << "isShare: " << userHistory[postShowArray[(choice * 2) - 2]]->getPostHistory()[postShowArray[(choice * 2) - 1]]->getIsShare() << endl;
            cout << "By: " << userHistory[postShowArray[(choice * 2) - 2]]->getPostHistory()[postShowArray[(choice * 2) - 1]]->getCreator() << endl;
        }
        else
        {
            cout << "wrong post number" << endl;
        }
    }
}

void createUser(ifstream &is, string userName, string password) {
    State mainState(is);
    mainState.createNewUser(userName, password);
    ofstream fs("State.txt");
    for (int i = 0; i < mainState.getNumOfUsers(); i++)
    {
        mainState.getUserHistory()[i]->write_to(fs);
    }
    
}

void createPost(ifstream &is, int userIndex, string description, string category, int price, bool isShare){
    State mainState(is);
    mainState.getUserHistory()[userIndex]->createPost(description, category, price, isShare);
    ofstream fs("State.txt");
    for (int i = 0; i < mainState.getNumOfUsers(); i++)
    {
        mainState.getUserHistory()[i]->write_to(fs);
    }

}

void createNotification(ifstream &is, int userFrom, int userTo, int postIndex, string message){
    State mainState(is);
    mainState.getUserHistory()[userTo]->getPostHistory()[postIndex]->createNotification(userFrom, message);
    ofstream fs("State.txt");
    for (int i = 0; i < mainState.getNumOfUsers(); i++)
    {
        mainState.getUserHistory()[i]->write_to(fs);
    }

}

void searchIsShare(ifstream &is){

    State mainState(is);
    ofstream fs("Sharing.txt");
    for (int i = 0; i < mainState.getNumOfUsers(); i++)
    {

        Post *array = mainState.getUserHistory()[i]->searchIsShare();
        int size = mainState.getUserHistory()[i]->getNumSharing();
        for (int j = 0; j < size; j++){
            fs << array[j].getDescription() << endl;
            fs << array[j].getCategory() << endl;
            fs << array[j].getPrice() << endl;
            fs << "Share" << endl;

        }


    }
       
        
 }
