#include "Post.h"

Post::Post(std::string text) {
    _text = std::move(text);
}

Post::Post(std::string text, Media *media) {
    _text = std::move(text);
    _media = media;
}

Post::~Post() {
    delete this->getMedia();
}


std::string Post::getText() const {
    return _text;
}

Media *Post::getMedia() const {
    return _media;
}

