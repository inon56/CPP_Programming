#pragma once
#include <map>
#include <iostream>

class User;

class USocial {
    private:
        std::map<unsigned long, User*> _users;
    public:
        ~USocial();
        User* registerUser(std::string, bool isBusinessUser = false);
        void removeUser(User*);
        [[nodiscard]] User* getUserById(unsigned long) const;
        [[nodiscard]] bool isRegisteredUser(unsigned long) const;
};


