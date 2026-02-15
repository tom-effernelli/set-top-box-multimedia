#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
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

bool Manager::processRequest(const std::string& request, std::string& response) {
    std::stringstream ss(request);
    std::string command, name;
    ss >> command >> name;

    if (command == "PLAY") {
        auto it = mediaTable.find(name);
        if (it != mediaTable.end()) {
            it->second->play();
            response = "OK: Playing " + name;
        } else {
            response = "Error: Media '" + name + "' not found.";
        }
    }
    else if (command == "DISPLAY") {
        std::stringstream output;
        display(name, output);
        response = output.str();
        std::replace(response.begin(), response.end(), '\n', ';');
    } 
    else if (command == "SAVE") {
        save("database.txt");
        response = "OK: Database saved.";
    }
    else if (command == "LOAD") {
        load("database.txt");
        response = "OK: Database loaded.";
    }
    else if (command == "QUIT") {
        response = "Bye!";
        return false;
    } 
    else {
        response = "Error: Unknown command.";
    }
    return true;
}

void Manager::save(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Erreur ouverture fichier" << std::endl;
        return;
    }
    for (auto const& pair : mediaTable) {
        pair.second->write(ofs);
    }
}

void Manager::load(const std::string& filename) {
    std::ifstream ifs(filename);
    
    if (!ifs) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << " en lecture." << std::endl;
        return;
    }

    std::string type;
    while (std::getline(ifs, type)) {
        
        std::string name, path;

        if (type == "Photo") {
            float lat, lon;
            std::getline(ifs, name);
            std::getline(ifs, path);
            ifs >> lat >> lon;
            ifs.ignore();
            
            this->createPhoto(name, path, lat, lon);
        }
        
        else if (type == "Video") {
            int duration;
            std::getline(ifs, name);
            std::getline(ifs, path);
            ifs >> duration;
            ifs.ignore();
            
            this->createVideo(name, path, duration);
        }
        
        else if (type == "Film") {
            int duration, count;
            std::getline(ifs, name);
            std::getline(ifs, path);
            ifs >> duration >> count;
            
            int* chapters = new int[count];
            for (int i = 0; i < count; ++i) {
                ifs >> chapters[i];
            }
            ifs.ignore();
            
            this->createFilm(name, path, duration, chapters, count);
            
            delete[] chapters;
        }
    }
    
    std::cout << "Chargement termine avec succes depuis " << filename << std::endl;
}