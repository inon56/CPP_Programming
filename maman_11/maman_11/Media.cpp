#include <iostream>
#include "Media.h"

Media::~Media() = default;

void Photo::display() const {
    std::cout << "Image" << '\n';
}

void Audio::display() const {
    std::cout << "Audio" << '\n';
}

void Video::display() const {
    std::cout << "Video" << '\n';
}
