#ifndef LOGINANDREGISTER_H
#define LOGINANDREGISTER_H
#include <string>
#include <iostream>

using namespace std;
class LoginAndRegister
{
private:
    string username, password;
public:
    LoginAndRegister();
    virtual bool registerUser();
    virtual bool loginUser();
    virtual void runCode();
    virtual ~LoginAndRegister() = default;

};

#endif // LOGINANDREGISTER_H
