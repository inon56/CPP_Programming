#pragma once
#include "Media.h"
#include <iostream>

class Post {
    private:
        std::string _text;
        Media* _media = nullptr;
    public:
        ~Post();
        explicit Post(std::string);
        Post(std::string, Media*);
        std::string getText() const;
        Media* getMedia() const;
};
