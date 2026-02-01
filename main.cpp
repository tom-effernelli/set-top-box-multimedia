#include <iostream>
#include <string>
#include "MultimediaObj.h"

int main() {
    // On crée des variables string d'abord
    std::string n = "Mon Image";
    std::string p = "images/photo.jpg";

    // Maintenant, le compilateur accepte car n et p sont des variables (l-values)
    MultimediaObj * m1 = new MultimediaObj(n, p);
    
    m1->display(std::cout);
    
    delete m1;
    return 0;
}