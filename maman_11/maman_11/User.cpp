#include <algorithm>
#include <iostream>
#include <exception>

#include "USocial.h"
#include "User.h"
#include "Exception.h"

unsigned long User::_nextID = 0;

User::User(){
    _id = ++_nextID; // unique user id
    _us = nullptr;
}

User::~User(){
    for(Post *post : _posts)
        delete post;
    for(Message *message : _receivedMsgs)
        delete message;
}

// remove the user argument from the curr object friends_list, and also remove the curr object from the user friends_list
void User::removeFriend(User* user){
    if(!(_us->isRegisteredUser(user->getId()))) //if given user not exist in usocial registered users list
        throw Exception("Given user does not exist in usocial registered users list.");
    else if(find(_friends.begin(), _friends.end(), user->_id) == _friends.end())
        throw Exception("Given user is not a friend of this user.");
    else{
        auto new_end = remove_if(user->_friends.begin(), user->_friends.end(), [this](unsigned long uid){return uid==this->_id;});
        user->_friends.erase(new_end,user->_friends.end());
        new_end = remove_if(this->_friends.begin(), this->_friends.end(), [user](unsigned long uid){return uid==user->_id;});
        this->_friends.erase(new_end,this->_friends.end());
    }
}

// When adding a friend user_1 to friends_list of user_2, we also need to add user_2 to friends_list of user_1.
// Thus, this is adding on user_1 friends_list
void User::addFriend(User* user){
    if(!(_us->isRegisteredUser(user->getId())))
        throw Exception("There is no user corresponding to given user id.");
    else if(find(_friends.begin(), _friends.end(), user->_id) != _friends.end())
        throw Exception("Friend is already exist.");
    else{
        _friends.push_back(user->_id);
        user->_friends.push_back(this->_id);
    }
}

void User::post(std::string text){
    Post *post = new Post(move(text));
    _posts.push_back(post);
}

void User::post(std::string text, Media *media){
    if(!media)
        post(text);
    else
        _posts.push_back(new Post(move(text), media));
}

//Display posts of all friends in this user friends list
void User::viewFriendsPosts() const{
    for(unsigned long friendId : _friends){
        User *f  = _us->getUserById(friendId);
        for(Post *post : f->_posts){
            std::cout << post->getText() << '\n';
            if(post->getMedia())
                post->getMedia()->display();
        }
    }
}

void User::receiveMessage(Message* message) {
    if(!message)
        throw Exception("Undefined message.");
    this->_receivedMsgs.insert(_receivedMsgs.end(), message);
}

void User::sendMessage(User* user, Message* message) const{
    if(!(_us->isRegisteredUser(user->getId())))
        throw Exception("There is no user corresponding to given user id.");
    else if(find(_friends.begin(), _friends.end(), user->_id) == _friends.end())
        throw Exception("Only business users could send messages to non friend user.");
    else
        user->receiveMessage(message);
}


void BusinessUser::sendMessage(User* user, Message *message) const{
    if(!(_us->isRegisteredUser(user->getId())))
        throw Exception("There is no user registered user corresponding to given user id.");
    user->receiveMessage(message);
}

void User::viewReceivedMessages() const{
    for(Message *msg : _receivedMsgs)
        std::cout << msg->getText() << '\n';
}

std::list<Post *> User::getPosts() const {
    return _posts;
}

unsigned long User::getId() const {
    return _id;
}

std::string User::getName() const {
    return _name;
}
