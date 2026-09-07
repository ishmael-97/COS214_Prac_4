#include "ProductionIterator.h"
#include "ProductionGroup.h"

// necessary library 
#include <algorithm>

// Concrte Iterator implementation #1 (Full Traversal in Pre-order DFS)
FullIterator::FullIterator(ProductionGroup* root) : root (root), current (nullptr) {
    first();
}

void FullIterator::first() {
    while (!traversalStack.empty()) {
        traversalStack.pop();
    }   

    current = nullptr;

    if (root != nullptr) {
        traversalStack.push(root);
        next();
    }
}

void FullIterator::next() {
    if (traversalStack.empty()) {
        current = nullptr;
        return;
    }

    current = traversalStack.top();
    traversalStack.pop();

    // IMPORTANANT: Used to decide if current component is composite to descend into its children
    ProductionGroup* group = dynamic_cast<ProductionGroup*>(current);

    if (group != nullptr) {
        for (std::vector<ProductionUnit*>::reverse_iterator it =
                 group->children.rbegin();
             it != group->children.rend();
             ++it) {
                traversalStack.push(*it);
        }
    }   
}

bool FullIterator::isDone() const { return current == nullptr; }

ProductionUnit* FullIterator::currentItem() const { return current; }

// Concrete Iterator implementation #2 
UrgentIterator::UrgentIterator(ProductionGroup* root)
    : fullIterator(new FullIterator(root)),
      current(nullptr)
{
    first();
}

// must iterate over urgent components
void UrgentIterator::first() {
    current = nullptr;

    fullIterator->first();

    while (!fullIterator->isDone()) {
        ProductionUnit* unit = fullIterator->currentItem();

        if (unit != nullptr && unit->isUrgent()) {
            current = unit;
            return;
        }

        fullIterator->next();
    }
}

void UrgentIterator::next() {
    current = nullptr;

    fullIterator->next();

    while (!fullIterator->isDone())
    {
        ProductionUnit* unit =
            fullIterator->currentItem();

        if (unit != nullptr && unit->isUrgent())
        {
            current = unit;
            return;
        }

        fullIterator->next();
    }
}

bool UrgentIterator::isDone() const { return current == nullptr; }

ProductionUnit* UrgentIterator::currentItem() const { return current; }

UrgentIterator::~UrgentIterator() { delete fullIterator; }