#include <iostream>
#include <string>
using namespace std;
#include "User.h"
#include "Post.h"
#include "Notification.h"

Notification::Notification(){ //Default constructor 
    message = "0";
    userFrom = -1;
    userTo = -1;
    
}
    
Notification :: Notification(int userF, int userT, string m){ 
    userFrom = userF;
    userTo = userT;
    message = m;
}

Notification::Notification(istream &is){
    string keyword;
    is >> keyword;
    is.get(); 
    if (keyword != "Notification") {
        cerr << "Error in Notification constructor!" << endl;
    }
    else{
        is.get();
        getline(is, message);
    }
}

string Notification::getMessage()const{
    return message;
}
int Notification::getUserFrom() const{
    return userFrom;
}

int Notification::getUserTo() const{
    return userTo;
}

void Notification::setUserFrom(int uf){
    userFrom = uf; 
}

void Notification::setUserTo(int ut){
    userTo = ut;
}



