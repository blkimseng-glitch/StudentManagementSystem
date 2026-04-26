#ifndef USER_MANAGER_HPP
#define USER_MANAGER_HPP

#include <string>

using namespace std;

enum class UserRole
{
    Admin,
    Teacher,
    Student,
    None
};

class UserManager
{
public:
    static UserRole login();
};

#endif