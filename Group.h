#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include "MultimediaObj.h"

class Group : public std::list<MultimediaObj*> {
    private:
        std::string groupName;

    public:
        Group();
        Group(std::string& name);
        virtual ~Group();

        std::string getName() const;
        
        void display(std::ostream& os) const;
};

#endif