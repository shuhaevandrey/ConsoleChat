#include <iostream>
#include "UsrCont.h"
#include "User.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    /*
    User* user = new User();
    user->getUsrData();
    */
    
    

    
    UsrCont* user = new UsrCont();
    user->getMainMenu();
    user->getUsrData();
    
    
    

    delete user;

    return 0;
}