#ifndef PHOTO_H 
#define PHOTO_H

#include <string>
#include <iostream>
#include "MultimediaObj.h"

class Photo : public MultimediaObj {
    private:
        float latitude{};
        float longitude{};
    public:
        Photo(std::string& name, std::string& path, float latitude, float longitude);
        Photo();
        virtual ~Photo() override;

        float getLatitude() const;
        float getLongitude() const;
        void setLatitude(float);
        void setLongitude(float);
        virtual std::ostream& display(std::ostream &os) const override; // prints instance variables into os output stream
        virtual void play() const;
};

#endif