#include "Video.h"

Video::Video() : MultimediaObj() {
    length = 0;
}

Video::Video(const std::string& name, const std::string& path, float len) : MultimediaObj(name, path) {
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
    std::string command = "vlc " + getPath() + " &";
    system(command.c_str());
}

void Video::write(std::ostream& os) const {
    os << "Video\n";
    MultimediaObj::write(os);
    os << length << "\n";
}