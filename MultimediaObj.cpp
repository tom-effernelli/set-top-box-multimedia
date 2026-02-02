#include "MultimediaObj.h"

MultimediaObj::MultimediaObj(const std::string& name, const std::string& path) {
    this->name=name;
    this->path=path;
}

MultimediaObj::MultimediaObj() {
    name="";
    path="";
}

MultimediaObj::~MultimediaObj() {}

std::string MultimediaObj::getName() const {
    return name;
}

std::string MultimediaObj::getPath() const {
    return path;
}

void MultimediaObj::setName(const std::string& n) {
    name=n;
}

void MultimediaObj::setPath(const std::string& p) {
    path=p;
}

std::ostream& MultimediaObj::display(std::ostream &os) const {
    os << "Name: " << getName() << " Path: " << getPath() << std::endl;
    return os;
}