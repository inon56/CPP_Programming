#pragma once

class Media {
    public:
        virtual void display() const = 0;
        virtual ~Media() = 0;
};

class Photo: public Media{
    public:
        void display() const override;
};

class Audio: public Media{
    public:
        void display() const override;
};

class Video: public Media{
    public:
        void display() const override;
};

