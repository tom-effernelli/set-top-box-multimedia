#include "Photo.h"

Photo::Photo() : MultimediaObj() {
    latitude = 0;
    longitude = 0;
}

Photo::Photo(const std::string& name, const std::string& path, float lat, float lon) : MultimediaObj(name, path) {
    this->latitude = lat;
    this->longitude = lon;
}

Photo::~Photo() {}

float Photo::getLatitude() const {
    return latitude;
}
float Photo::getLongitude() const {
    return longitude;
}

void Photo::setLatitude(float lat) {
    latitude = lat;
}
void Photo::setLongitude(float lon) {
    longitude = lon;
}

std::ostream& Photo::display(std::ostream &os) const {
    MultimediaObj::display(os);
    os << "Latitude: " << latitude << " Longitude: " << longitude << std::endl;
    return os;
}

void Photo::play() const {
    std::string command = "xdg-open " + getPath() + " &";
    system(command.c_str());
}

void Photo::write(std::ostream& os) const {
    os << "Photo\n";
    MultimediaObj::write(os);
    os << latitude << "\n" << longitude << "\n";
}