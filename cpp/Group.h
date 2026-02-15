#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "MultimediaObj.h"

typedef std::shared_ptr<MultimediaObj> MultimediaPtr;

class Group : public std::list<MultimediaPtr> {
    private:
        std::string groupName;

    public:
        Group();
        Group(const std::string& name);
        virtual ~Group();

        std::string getName() const;
        
        void display(std::ostream& os) const;
};

#endif