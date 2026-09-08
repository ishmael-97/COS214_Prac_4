// Note that Urgent/Full Iterator are in one .h
#include "ProductionGroup.h"
#include "ProductionIterator.h"

// necessary library
#include <algorithm>

// Constructor
ProductionGroup::ProductionGroup(const std::string& name) : name (name) {}

// add a unit
void ProductionGroup::add(ProductionUnit* unit) {
    // check if there is unit
    if (unit != nullptr) {
        children.push_back(unit);
    }
}

// remove a unit
void ProductionGroup::remove(ProductionUnit* unit) {
    // no unit do nothing
    if (unit == nullptr) {
        return;
    }

    std::vector<ProductionUnit*>::iterator it = std::find(children.begin(), children.end(), unit);

    if (it != children.end()) {
        delete *it;
        children.erase(it);
    }
}

// get name of part of work-structure
std::string ProductionGroup::getName() const { return this->name; }

// returns number of units contained here
std::string ProductionGroup::getStatus() const {
    if (children.empty()) { return "Empty"; }
    // units -> children
    return "Contains " + std::to_string(children.size()) + " units";
}

// looks for units that need to be prioritized
bool ProductionGroup::isUrgent() const {
    for (std::vector<ProductionUnit*>::const_iterator it = children.begin();
         it != children.end(); ++it) {
            if ((*it)->isUrgent()) {
                return true;
            }
    }

    // not important 
    return false;
}

// Used to Traverse the entire structure
ProductionIterator* ProductionGroup::createFullIterator() {
    return new FullIterator(this);
}

//Used to Traverse part of the structure that need to be prioritized
ProductionIterator* ProductionGroup::createUrgentIterator() {
    return new UrgentIterator(this);
}

// Own its children so it  must delete them
ProductionGroup::~ProductionGroup() {
    for (std::vector<ProductionUnit*>::iterator it =
             children.begin(); it != children.end(); ++it)
    {
        delete *it;
    }

    children.clear();
}

// Concrete Composite class implementation

// #1
Act::Act(const std::string& name) : ProductionGroup(name) {}

// #2 
Sequence::Sequence(const std::string& name) : ProductionGroup(name) {}

// #3 
Scene::Scene(const std::string& name) : ProductionGroup(name) {}

void ProductionGroup::execute() {
    return;
}
