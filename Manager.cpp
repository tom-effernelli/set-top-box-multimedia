#include <iostream>
#include "Manager.h"

std::shared_ptr<Photo> Manager::createPhoto(std::string name, std::string path, float lat, float lon) {
    std::shared_ptr<Photo> photo = std::make_shared<Photo>(name, path, lat, lon);
    mediaTable[name] = photo;
    return photo;
}

std::shared_ptr<Video> Manager::createVideo(std::string name, std::string path, int duration) {
    std::shared_ptr<Video> video = std::make_shared<Video>(name, path, duration);
    mediaTable[name] = video;
    return video;
}

std::shared_ptr<Film> Manager::createFilm(std::string name, std::string path, int duration, int * chapters, int numChapters) {
    std::shared_ptr<Film> film = std::make_shared<Film>(name, path, duration, chapters, numChapters);
    mediaTable[name] = film;
    return film;
}

GroupPtr Manager::createGroup(std::string name) {
    GroupPtr group = std::make_shared<Group>(name);
    groupTable[name] = group;
    return group;
}

void Manager::display(std::string name, std::ostream& os) const {
    auto itMedia = mediaTable.find(name);
    if (itMedia != mediaTable.end()) {
        itMedia->second->display(os);
        return;
    }

    auto itGroup = groupTable.find(name);
    if (itGroup != groupTable.end()) {
        itGroup->second->display(os);
    } else {
        os << "Error: Object or group '" << name << "' doesn't exists." << std::endl;
    }
}

void Manager::play(std::string name) const {
    auto it = mediaTable.find(name);
    if (it != mediaTable.end()) {
        it->second->play();
    } else {
        std::cout << "Error: Unable to play '" << name << "' (not found)." << std::endl;
    }
}