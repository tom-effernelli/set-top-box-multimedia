#ifndef VIDEO_H 
#define VIDEO_H

#include <string>
#include <iostream>
#include "MultimediaObj.h"

class Video : public MultimediaObj {
    private:
        float length{};
    public:
        Video(std::string& name, std::string& path, float length);
        Video();
        virtual ~Video() override;

        float getLength() const;
        void setLength(float);
        virtual std::ostream& display(std::ostream &os) const override; // prints instance variables into os output stream
        virtual void play() const;
};

#endif