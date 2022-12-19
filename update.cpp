#include "State.h"
#include"/usr/local/cs/cs251/react.h"
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
    username = _global_mem[3];
    password = _global_mem[4];
    createNewUser(username, password);
    //displayHome();
}

void State::updateHome()
{
    int choice;
    //cout << "to exit enter 0 or to see the post enter the order of the post (i.e. 3 for 3rd post): ";
    //cin >> choice;
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
            exit(1);
        }
    }
}


 void State:: stateCreatePost(int currentUserIndex){
      string des, cat;
        int pr;
        bool isShare;
        cout << "Enter description: ";
        cin >> des;
        cout << "Enter category: ";
        cin >> cat;
        cout << "Enter price: ";
        cin >> pr;
        cout << "Are you sharing the post: ";
        cin >> isShare;
        getUserHistory()[currentUserIndex]->createPost(des, cat, pr, isShare);
        ofstream of("curr_state");
        writeTo(of);

 }

 void State::makeRequest(int senderIndex) {

    int postNumber;
    cout << "Which post you want to  make a request for? " << endl;
    cin >> postNumber;

    string msg;
    cout << "Write a message to request this product/service: " << endl;
    cin >> msg;

    int size = 0;

        for (int i = 0; i < getNumOfUsers(); i++)
        {
            for (int j = 0; j < getUserHistory()[i]->numOfPosts; j++)
            {
                size++;
                // cout << "Size: " << size << endl;
            }
        }
        int doublesize = size * 2;

        int postShowArray[doublesize];

        int repeater = 0;

        for (int i = 0; i < getNumOfUsers(); i++)
        {
            for (int j = 0; j < getUserHistory()[i]->numOfPosts; j++)
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

        if (postNumber <= size)
        {
            getUserHistory()[postShowArray[(postNumber * 2) - 2]]->getPostHistory()[postShowArray[(postNumber * 2) - 1]]->createNotification(senderIndex, msg);

        }
        else
        {
            cout << "wrong post number" << endl;
        }

    ofstream of("curr_state");
    writeTo(of);

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
 void State::handle_button_event(int button){
    string usrnm;
    string pswrd; 
    string signUpUsername;
    string signUpPassword;
    int size;
     if (button == 3){
         _add_yaml("login.yaml");
         }
     else if (button == 4)
     {
        string s1;
        for (int i = 0; i < 20; i++)
        {
          s1 = _global_mem[22+i];
          if (s1 != "~")
          {
            usrnm.append(s1);  
          }
          
        }
        input_username = usrnm;
        string s2;
        for (int i = 0; i < 20; i++)
        {
          s2 = _global_mem[54+i];
          if (s2 != "~")
          {
            pswrd.append(s2);  
          }
          
        }
        input_password = pswrd;
        //cerr << "username: " << input_username << endl;
        //cerr << "password: " << input_password << endl;
        if (userExist(input_username, input_password) != -1)
        {
            currentUserIndex = userExist(input_username, input_password);
            cout << "CurrentUser " << currentUserIndex << endl;
            int *arr =  offset_for_posts(size);
            //cout << "Size : " << size << endl;
            
            _add_yaml("home_page.yaml");

            for (int i = 0; i < size; i++)
            {
                _add_yaml("post_button.yaml", { {"button_id", "buttonId_" + to_string(i)}, {"post_index", arr[i*4] + 375}, {"top_shift", 30*i + 135 } });
            }
            
            
        }
        else {
            _add_yaml("sign_up.yaml");

        }
         
     }
     else if (button == 1)
     {
        _add_yaml("sign_up.yaml");
     }

     else if (button == 2)
     {
        string s1;
        for (int i = 0; i < 20; i++)
        {
          s1 = _global_mem[22+i];
          if (s1 != "~")
          {
           signUpUsername.append(s1);  
          }
          
        }
        input_username = signUpUsername.substr(0, signUpUsername.length()-1);
        string s2;
        for (int i = 0; i < 20; i++)
        {
          s2 = _global_mem[54+i];
          if (s2 != "~")
          {
            signUpPassword.append(s2);  
          }
          
        }
        input_password = signUpPassword.substr(0, signUpPassword.length()-1);

         createNewUser(input_username, input_password);
         currentUserIndex = numOfUsers-1;
         cout << "currentUser" << currentUserIndex << endl;
         cout << "num_of_users: " << numOfUsers << endl;
        int *arr =  offset_for_posts(size);
        _add_yaml("home_page.yaml");
        for (int i = 0; i < size; i++)
        {
            _add_yaml("post_button.yaml", { {"button_id", "buttonId_" + to_string(i)}, {"post_index", arr[i*4] + 375}, {"top_shift", 30*i + 135 } });
        }
    
     }

     else if ( button == 9 )
     {
        int *arr =  offset_for_posts(size);
        _add_yaml("home_page.yaml");

        for (int i = 0; i < size; i++)
        {
            _add_yaml("post_button.yaml", { {"button_id", "buttonId_" + to_string(i)}, {"post_index", arr[i*4] + 375}, {"top_shift", 30*i + 135 } });
        }
     }

     else if ( button == 10)
     {
         _add_yaml("send_Notification.yaml");
        
     }
     else if ( button == 11)
     {
        string notUsername;
        string notPassword; 
        string s1;
            for (int i = 0; i < 20; i++)
            {
                s1 = _global_mem[22+i];
                if (s1 != "~")
                {
                notUsername.append(s1);  
                }
                
            }
            input_username = notUsername;
            string s2;
            for (int i = 0; i < 20; i++)
            {
                s2 = _global_mem[54+i];
                if (s2 != "~")
                {
                notPassword.append(s2);  
                }
                
            }
            input_password = notPassword;
            currentUserIndex = userExist(input_username, input_password);

        if ( currentUserIndex != -1)
        {
            string s;
            string message;
            for (int i = 0; i < 100; i++)
            {
                s = _global_mem[233+i];
                if (s != "~")
                {
                    message.append(s);  
                }
            
            }
            int userToIndx, postToIndx;
            postIndexFinder(userToIndx, postToIndx);
            message = message.substr(0, message.length()-1);
            userHistory[userToIndx]->getPostHistory()[postToIndx]->createNotification(currentUserIndex, message);
            cout << "current_user " << realTimeIndex << endl;
            int *arr =  offset_for_posts(size);
            _add_yaml("home_page.yaml");

            for (int i = 0; i < size; i++)
            {
                _add_yaml("post_button.yaml", { {"button_id", "buttonId_" + to_string(i)}, {"post_index", arr[i*4] + 375}, {"top_shift", 30*i + 135 } });
            }
        }
        else {
            _add_yaml("send_Notification.yaml");

        }
        
        
     }
     else if ( button == 12 || button == 5 || button == 6)
     {
         _add_yaml("send_Notification.yaml");
        
     }
     else if ( button == 7) // home page create post button
     {
        _add_yaml("create_post.yaml");
        
     }
     else if ( button == 8) // create post page create post button
     {
         
            string s, message, description, category;
            int price;
            bool IsShare;
            for (int i = 0; i < 50; i++) // getting the description from th global mem
            {
                s = _global_mem[89+i];
                if (s != "~")
                {
                    message.append(s);  
                }
            
            }
            description = message.substr(0, message.length()-1);
            message = "";
            s = "";
            for (int i = 0; i < 20; i++) // getting the category from th global mem
            {
                s = _global_mem[151+i];
                if (s != "~")
                {
                    message.append(s);  
                }
            
            }
            category = message.substr(0, message.length()-1);
            message = "";
            s = "";
            for (int i = 0; i < 20; i++) // getting the price from th global mem
            {
                s = _global_mem[180+i];
                if (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "5" || s == "6" || s == "7" || s == "8" || s == "9" )
                {
                    message.append(s);  
                }
            
            }
            price = stoi(message);
            message = "";
            s = "";
            for (int i = 0; i < 10; i++) // getting the IsShare from th global mem
            {
                s = _global_mem[213+i];
                if (s == "0" || s == "1")
                {
                    message.append(s);  
                }
            
            }
            if (message == "1")
            {
                IsShare = true;
            }
            else if (message == "0")
            {
                IsShare = false;
            }
            message = "";
            s = "";

            string notUsername;    // this section finds the index for the current user the user who is creating the post
            string notPassword; 
            string s1;
            for (int i = 0; i < 20; i++)
            {
                s1 = _global_mem[22+i];
                if (s1 != "~")
                {
                notUsername.append(s1);  
                }
                
            }
            input_username = notUsername;
            string s2;
            for (int i = 0; i < 20; i++)
            {
                s2 = _global_mem[54+i];
                if (s2 != "~")
                {
                notPassword.append(s2);  
                }
                
            }
            input_password = notPassword;
            currentUserIndex = userExist(input_username, input_password);
            userHistory[currentUserIndex]->createPost(description, category, price, IsShare);
            handle_button_event(9);
        
     }
     else if (button == 13 || button == 14 || button == 15 || button == 16) 
     {
         _add_yaml("create_post.yaml");
         
     }
     else if (button == 17)
     {
         _add_yaml("search_post.yaml");
    
     }
     else if (button == 18)
     {
        int *arr =  offset_for_posts(size);
        _add_yaml("home_page.yaml");
        int size;
        int *array = stateSearchDescription(size);
        for (int i = 0; i < size; i++)
        {

            _add_yaml("post_button.yaml", {{"button_id", "buttonId_" + to_string(array[i])}, {"post_index", arr[array[i]*4] + 375}, {"top_shift", 30*array[i] + 135 }});

             
        }
         
     }
     else if (button == 19)
     {
        _add_yaml("home_page.yaml");

        int size = 0;
        string notUsername;
        string notPassword; 
        string s1;
            for (int i = 0; i < 20; i++)
            {
                s1 = _global_mem[22+i];
                if (s1 != "~")
                {
                notUsername.append(s1);  
                }
                
            }
            input_username = notUsername;
            string s2;
            for (int i = 0; i < 20; i++)
            {
                s2 = _global_mem[54+i];
                if (s2 != "~")
                {
                notPassword.append(s2);  
                }
                
            }
            input_password = notPassword;
            currentUserIndex = userExist(input_username, input_password);

        int *array = offsetForNotification(size, currentUserIndex);
        /*for (int i = 0; i < size; i++)
        {
            cout << "array i" << array[i*3] << endl;
            cout << "array i" << array[i*3+1] << endl;
            cout << "array i" << array[i*3+2] << endl;
            
        }*/
        
        cout << "userindx " << currentUserIndex << "Size " << size << endl;
        for (int i = 0; i < size; i++)
        {
            _add_yaml("post_button.yaml", { {"button_id", "notificationId"}, {"post_index", array[i*3] + 375}, {"top_shift", 30*i + 135 } });
        }
        

     }
     
     
     
     

     else if (button == 0)
     {
        int size;
        int *arr = offset_for_posts(size);
        for (int i = 0; i < size; i++)
        {
            
            if (_event_id_is("buttonId_", i))
            {
                string indx = to_string(i);
                indx.copy(_global_mem + 355, indx.length());

                _add_yaml("individual_post.yaml", {{"description_index", arr[i*4] + 375}, {"category_index", arr[i*4+1] + 375}, {"price_index", arr[i*4+2] + 375}, {"isShare_index", arr[i*4+3] + 375}});
                
            }
            
        }
     }

     
     
     
     
     
     
 }

 void State::update(){

  if (_received_event())
  {
  
        if (_event_id_is("button_", 3)){
          handle_button_event(3);
        }

        else if (_event_id_is("button_", 4)) { 
          handle_button_event(4);

        }
        else if (_event_id_is("button_", 5))
        {
            handle_button_event(5);
        }
        else if (_event_id_is("button_", 6))
        {
            handle_button_event(6);
        }
        else if (_event_id_is("button_", 7))
        {
            handle_button_event(7);
        }
        else if (_event_id_is("button_", 8))
        {
            handle_button_event(8);
        }
        
        else if(_event_id_is("button_", 1)) {
            handle_button_event(1);
          
        }

        else if (_event_id_is("button_", 2))
        {
            handle_button_event(2);
        }
        
        else if(_event_id_is("button_", 9)){
            handle_button_event(9);
        }
        else if(_event_id_is("button_", 10)){
            handle_button_event(10);
        }
        else if(_event_id_is("button_", 11)){
            handle_button_event(11);
        }
        else if(_event_id_is("button_", 12)){
            handle_button_event(12);
        }
        else if(_event_id_is("button_", 13)){
            handle_button_event(13);
        }
        else if(_event_id_is("button_", 14)){
            handle_button_event(14);
        }
        else if(_event_id_is("button_", 15)){
            handle_button_event(15);
        }
        else if(_event_id_is("button_", 16)){
            handle_button_event(16);
        }
        else if(_event_id_is("button_", 17)){
            handle_button_event(17);
        }
        else if(_event_id_is("button_", 18)){
            handle_button_event(18);
        }
        else if (_event_id_is("button_", 19))
        {
            handle_button_event(19);
        }
        else if (_event_id_is("notificationId")){
            handle_button_event(19);
        }
        
        else {
            int size;
            int *arr = offset_for_posts(size);
            for (int i = 0; i < size; i++)
            {
                if (_event_id_is("buttonId_", i))
                {
                    handle_button_event(0);
                }
                
            }
            
        }
        
    }
    else {
        _add_yaml("login.yaml");

    }
 }

