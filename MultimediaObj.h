#ifndef MULTIMEDIAOBJ_H
#define MULTIMEDIAOBJ_H

#include <string>
#include <iostream>

class MultimediaObj {
    private:
        std::string name{};
        std::string path{};
    public:
        MultimediaObj(std::string& name, std::string& path);
        MultimediaObj();

        virtual ~MultimediaObj();

        std::string getName() const;
        std::string getPath() const;
        void setName(std::string& n);
        void setPath(std::string& p);
        virtual std::ostream& display(std::ostream &os) const; // prints instance variables into os output stream
        virtual void play() const = 0;
};

#endif