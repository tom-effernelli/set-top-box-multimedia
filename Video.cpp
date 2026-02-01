#include "Video.h"

Video::Video() : MultimediaObj() {
    length = 0;
}

Video::Video(std::string& name, std::string& path, float len) : MultimediaObj(name, path) {
    this->length = len;
}

Video::~Video() {}

float Video::getLength() const {
    return length;
}

void Video::setLength(float len) {
    length = len;
}

std::ostream& Video::display(std::ostream &os) const {
    MultimediaObj::display(os);
    os << "Length: " << length << std::endl;
    return os;
}

void Video::play() const {
    std::string command = "mpv " + getPath() + " &";
    system(command.c_str());
}