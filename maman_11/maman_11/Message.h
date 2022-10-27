#pragma once
#include <iostream>

class Message {
    private:
        std::string _text;
    public:
        explicit Message(std::string text);
        std::string getText();
};


