int State::StateLoop(istream &is)
{
    string keyword;
    getline(is, keyword, '~');
    is.get();
    if (is.eof())
    {
        cout << "The file ended." << endl;
        return -1;
    }
    else if (keyword == "User")
    {
        string userName;
        string password;
        getline(is, userName, '~');
        is.get();
        getline(is, password, '~');
        is.get();
        createNewUser(userName, password);
        //cout << "New user created." << endl;
        StateLoop(is);
    }
    else if (keyword == "Post")
        {
        
            string description;
            getline(is, description, '~');
            is.get();
            string category;
            getline(is, category, '~');
            is.get();
            float price;
            getline(is, price, '~');
            is.get();
            bool isShare;
            getline(is, isShare, '~');
            is.get();
            int postIndex;
            getline(is, postIndex, '~');
            is.get();
            getUserHistory()[numOfUsers - 1]->createPost(description, category, price, isShare);
            //cout << "New post created" << endl;
            StateLoop(is);
            
        }
    else if (keyword == "Notification")
            {
                string msg;
                getline(is, msg, '~');
                //is.get();
                int userFrom;
                getline(is, userFrom, '~');
                is.get();
                int userTo;
                getline(is, userTo, '~');
                is.get();
                getUserHistory()[numOfUsers - 1]->getPostHistory()[(getUserHistory()[numOfUsers - 1]->numOfPosts) - 1]->createNotification(userFrom, msg);
                StateLoop(is);
                
            }

    }
