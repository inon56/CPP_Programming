#include "Message.h"

Message::Message(std::string text) {
    _text = std::move(text); //'text' is passed by value and only copied once, moving it to avoid unnecessary copies
}

std::string Message::getText() {
    return _text;
}
