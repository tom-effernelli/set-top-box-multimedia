#include "MultimediaObj.h"

MultimediaObj::MultimediaObj(std::string name, std::string path) {
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

void MultimediaObj::setName(std::string n) {
    name=n;
}

void MultimediaObj::setPath(std::string p) {
    path=p;
}

std::ostream& MultimediaObj::display(std::ostream &os) const {
    os << "Nom: " << getName() << " Path: " << getPath() << std::endl;
    return os;
}