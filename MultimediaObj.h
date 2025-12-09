#include <string>
#include <iostream>

class MultimediaObj {
    private:
        std::string name{};
        std::string path{};
    public:
        MultimediaObj(std::string name, std::string path);
        MultimediaObj();

        ~MultimediaObj();

        std::string getName() const;
        std::string getPath() const;
        void setName(std::string);
        void setPath(std::string);
        std::ostream& display(std::ostream &os) const;
}