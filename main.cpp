#include <iostream>
#include <string>
#include "Photo.h"
#include "Video.h"

int main() {
    std::string n1 = "Vacations", p1 = "vacations.jpg";
    std::string n2 = "Film", p2 = "movie.mp4";

    const int count = 2;
    MultimediaObj ** inventaire = new MultimediaObj*[count];

    inventaire[0] = new Photo(n1, p1, 48.8, 2.3);
    inventaire[1] = new Video(n2, p2, 120);

    for (int i = 0; i < count; i++) {
        inventaire[i]->display(std::cout);
        inventaire[i]->play();
    }

    for (int i = 0; i < count; i++) {
        delete inventaire[i];
    }
    delete[] inventaire;

    return 0;
}