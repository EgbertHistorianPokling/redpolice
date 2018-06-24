#ifndef __MODEL_USER_H__
#define __MODEL_USER_H__


#include <string>

using namespace std;

class User
{
public:
    User(User const &) = delete;
    void operator=(User const &) = delete;
    
    static User* getInstance()
    {
        static User INSTANCE;
        return &INSTANCE;
    }

    void setUID(const string & uid) { this->uid = uid; }
    string getUID() const { return uid; }

    void setName(const string& name) { this->name = name; };
    string getName() const { return name; };

private:
    User() {};

    string uid;
    string name;
};

#endif



