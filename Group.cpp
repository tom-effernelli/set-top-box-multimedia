#include "Group.h"

Group::Group(std::string& name) : std::list<MultimediaPtr>() {
    this->groupName = name;
}

Group::~Group() {}

std::string Group::getName() const {
    return groupName;
}

void Group::display(std::ostream& os) const {
    os << "Group: " << groupName << std::endl;
    
    for (auto it = this->begin(); it != this->end(); ++it) {
        (*it)->display(os);
    }
}