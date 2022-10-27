#include <algorithm>
#include <utility>

#include "USocial.h"
#include "User.h"
#include "Exception.h"

USocial::~USocial(){
    for(std::pair<const unsigned long, User *> u : _users)
        delete u.second;
}

User* USocial::getUserById(unsigned long id) const{
    if(!isRegisteredUser(id))
        throw Exception("There is no user corresponding to given user id.");
    return _users.find(id)->second;
}

bool USocial::isRegisteredUser(unsigned long uid) const{
    return _users.find(uid) != _users.end();
}


User* USocial::registerUser(std::string name, bool isBusinessUser){
    User *user = isBusinessUser ? new BusinessUser() : new User();
    user->_name = move(name);
    user->_us = this;
    _users.insert({user->_id,user});
    return user;
}

void USocial::removeUser(User* user){
    if(!isRegisteredUser(user->_id))
        throw Exception("Given user is not a registered user.");
    
    // removing the friend from all friends_lists of other users
    for(std::pair<const unsigned long, User *> uPair : _users){
        try{
            uPair.second->removeFriend(user);
        }
        catch(const std::exception& e){} // in case the users are not friends we will do nothing
    }
    
    _users.erase(user->_id); // removing the user from the USocial users_list
    delete user;
}