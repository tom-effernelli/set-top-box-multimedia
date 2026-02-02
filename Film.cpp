#include "Film.h"

Film::Film() : Video() {
    chapterDurations = nullptr;
    numberOfChapters = 0;
}

Film::Film(const std::string& name, const std::string& path, int duration, int * chapters, int numChapters) : Video(name, path, duration) {
    setChapters(chapters, numChapters);
}

Film::Film(const Film& from) : Video(from) {
    this->chapterDurations = nullptr; 
    
    this->setChapters(from.chapterDurations, from.numberOfChapters);
}

Film::~Film() {
    delete[] chapterDurations;
}

void Film::setChapters(const int * chapters, int numChapters) {
    delete[] chapterDurations;
    
    if (numChapters > 0 && chapters != nullptr) {
        chapterDurations = new int[numChapters];
        this->numberOfChapters = numChapters;

        for (int i = 0; i < numChapters; i++) {
            chapterDurations[i] = chapters[i];
        }
    } else {
        chapterDurations = nullptr;
        this->numberOfChapters = 0;
    }
}

const int * Film::getChapters() const {
    return chapterDurations;
}

int Film::getNumberOfChapters() const {
    return numberOfChapters;
}

std::ostream& Film::display(std::ostream &os) const {
    Video::display(os);
    os << "Number of chapters: " << numberOfChapters << std::endl;
    for (int i = 0; i < numberOfChapters; i++) {
        os << "  Chapter " << i << ": " << chapterDurations[i] << "s";
    }
    os << std::endl;
    return os;
}

void Film::write(std::ostream& os) const {
    os << "Film\n"              // 1. Le type (pour le load)
       << getName() << "\n"      // 2. Nom
       << getPath() << "\n"      // 3. Chemin
       << getLength() << "\n"  // 4. Durée (héritée de Video)
       << getNumberOfChapters() << "\n"; // 5. Nombre de chapitres

    for (int i = 0; i < getNumberOfChapters(); ++i) {
        os << getChapters()[i] << (i == getNumberOfChapters() - 1 ? "" : " ");
    }
    os << "\n"; 
}