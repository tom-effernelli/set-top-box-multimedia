#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video {
    private:
        int * chapterDurations = nullptr;
        int numberOfChapters = 0;
    public:
        Film();
        Film(const std::string& name, const std::string& path, int duration, int * chapters, int numChapters);

        Film(const Film& from);
        
        virtual ~Film();

        void setChapters(const int * chapters, int numChapters);
        const int * getChapters() const;
        int getNumberOfChapters() const;

        virtual std::ostream& display(std::ostream &os) const override;
        void write(std::ostream& os) const;
};

#endif