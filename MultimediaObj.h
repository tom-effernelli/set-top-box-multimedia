#ifndef MULTIMEDIAOBJ_H
#define MULTIMEDIAOBJ_H

#include <string>
#include <iostream>

class MultimediaObj {
    private:
        std::string name{};
        std::string path{};
    public:
        MultimediaObj(const std::string& name, const std::string& path);
        MultimediaObj();

        virtual ~MultimediaObj();

        std::string getName() const;
        std::string getPath() const;
        void setName(const std::string& n);
        void setPath(const std::string& p);
        virtual std::ostream& display(std::ostream &os) const; // prints instance variables into os output stream
        virtual void play() const = 0;
};

#endif