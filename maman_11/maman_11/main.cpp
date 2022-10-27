#include "USocial.h"
#include "User.h"

#include <exception>
#include <iostream>

int main() {

    USocial us;
    User *u1 = us.registerUser("Lev");
    User *u2 = us.registerUser("May");
    User *u3 = us.registerUser("Or");
    User *u5 = us.registerUser("Bar");
    User *u6 = us.registerUser("Gal");
    User *u7 = us.registerUser("Omri", true);

    u1->post("Hello world!");
    u2->post("I'm having a great time here :)", new Audio());
    u3->post("This is awesome!", new Photo());

    u5->addFriend(u1);
    u5->addFriend(u2);
    u6->addFriend(u2);
    u7->addFriend(u3);
    u7->addFriend(u2);
    u7->addFriend(u1);

    u3->sendMessage(u7, new Message("u3 -> send message to u7"));
    u3->post("u3 post !!", new Video());
    u2->sendMessage(u7, new Message("u2 -> send message u7"));
    u5->viewFriendsPosts();
    u7->viewFriendsPosts();
    u7->viewReceivedMessages();
    u6->addFriend(u7);
    u6->sendMessage(u7, new Message("U6 send message to u7"));
    u7->viewReceivedMessages();
    u7->viewReceivedMessages();
    u7->removeFriend(u3);
    u7->viewReceivedMessages();
    auto *m = new Message("u3 -> send message to u7 *after remove*");
    try{
        u3->sendMessage(u7, m);
    }
    catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        delete m;
        m = nullptr;
    }
    u6->addFriend(u5);
    u5->sendMessage(u6, new Message("u5 -> send message to u6 : Hi"));
    u5->post("u5 post Video!!", new Video());
    u6->viewFriendsPosts();
    return 0;
}