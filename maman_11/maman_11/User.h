#pragma once
#include <list>
#include "Post.h"
#include "Message.h"

class USocial;
class User {
    protected:
        USocial* _us;
        std::string _name;
        std::list<unsigned long> _friends;
        std::list<Post*> _posts;
        std::list<Message*> _receivedMsgs;
        User();
        ~User();
        unsigned long _id;
        static unsigned long _nextID;
    public:
        [[nodiscard]] unsigned long getId() const;
        [[nodiscard]] std::string getName() const;
        void addFriend(User*);
        void removeFriend(User*);
        void post(std::string);
        void post(std::string, Media*);
        [[nodiscard]] std::list<Post*> getPosts() const;
        void viewFriendsPosts() const;
        void receiveMessage(Message*);
        virtual void sendMessage(User*, Message*) const;
        void viewReceivedMessages() const;
        friend class USocial;
};

class BusinessUser: public User{
    public:
        void sendMessage(User*, Message*) const override;
};

