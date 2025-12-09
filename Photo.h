#include <string>
#include <iostream>

class Photo : public MultimediaObj {
    private:
        float latitude{};
        float longitude{};
    public:
        Photo(std::string name, std::string path, float latitude, float longitude);
        Photo();
        ~Photo();
        float getLatitude() const;
        float getLongitude() const;
        void setLatitude(float);
        void setLongitude(float);
        std::ostream& display(std::ostream &os) const override; # prints instance variables into os output stream
};