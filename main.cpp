#include <iostream>
#include <memory>
#include <string>
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;

int main() {
    std::cout << "--- Debut du programme (Gestion Auto) ---" << std::endl;

    PhotoPtr p1 = std::make_shared<Photo>("TourEiffel", "eiffel.jpg", 48.8, 2.2);
    VideoPtr v1 = std::make_shared<Video>("ChatRigolo", "cat.mp4", 30);
    
    int chapters[] = {10, 20, 30};
    FilmPtr f1 = std::make_shared<Film>("Inception", "inception.avi", 60, chapters, 3);

    GroupPtr g1 = std::make_shared<Group>("Vacances");
    GroupPtr g2 = std::make_shared<Group>("Favoris");

    g1->push_back(p1);
    g1->push_back(v1);

    g2->push_back(p1);
    g2->push_back(f1);

    std::cout << "\n--- Affichage du Groupe 1 ---" << std::endl;
    g1->display(std::cout);

    std::cout << "\n--- Affichage du Groupe 2 ---" << std::endl;
    g2->display(std::cout);

    std::cout << "\n--- Suppression du Groupe 1 ---" << std::endl;
    g1.reset();
    
    std::cout << "v1 est toujours la : " << v1->getName() << std::endl;

    std::cout << "\n--- Fin du programme ---" << std::endl;
    
    return 0;
}