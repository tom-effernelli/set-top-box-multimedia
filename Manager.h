#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <string>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using MultimediaPtr = std::shared_ptr<MultimediaObj>;
using GroupPtr = std::shared_ptr<Group>;

class Manager {
private:
    std::map<std::string, MultimediaPtr> mediaTable;
    std::map<std::string, GroupPtr> groupTable;

public:
    Manager() {}
    ~Manager() {}

    std::shared_ptr<Photo> createPhoto(std::string name, std::string path, float lat, float lon);
    std::shared_ptr<Video> createVideo(std::string name, std::string path, int duration);
    std::shared_ptr<Film>  createFilm(std::string name, std::string path, int duration, int * chapters, int numChapters);
    GroupPtr createGroup(std::string name);

    void display(std::string name, std::ostream& os) const;
    void play(std::string name) const;

    bool processRequest(const std::string& request, std::string& response);
};

#endif