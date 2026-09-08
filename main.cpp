#include "ProductionUnit.h"
#include "ProductionGroup.h"
#include "ProductionIterator.h"
#include "Shot.h"
#include "PriorityDecorator.h"
#include "InsuranceDecorator.h"
#include <iostream>

void printAll(ProductionIterator* it, const std::string& label) {
    std::cout << "--- " << label << " ---" << std::endl;
    for (it->first(); !it->isDone(); it->next()) {
        ProductionUnit* unit = it->currentItem();
        std::cout << unit->getStatus() << (unit->isUrgent() ? "  (URGENT)" : "") << std::endl;
    }
}

int main() {
    // ---- Build a 3-level nested hierarchy: Act -> Sequence -> Scene -> Shot ----
    Act* act = new Act("Act 1");
    Sequence* seq = new Sequence("Opening Sequence");
    Scene* scene1 = new Scene("Rooftop Scene");
    Scene* scene2 = new Scene("Car Chase Scene");

    Shot* shotA = new Shot("Wide establishing shot");
    Shot* shotB = new Shot("Close-up on hero");
    Shot* shotC = new Shot("Stunt jump");

    scene1->add(shotA);
    scene1->add(shotB);

    // Stack two decorators on shotC before adding it - the decorated object
    // is still usable as a plain ProductionUnit by the group that holds it
    ProductionUnit* decoratedShotC = new PriorityDecorator(new InsuranceDecorator(shotC, 500000.0));
    scene2->add(decoratedShotC);

    seq->add(scene1);
    seq->add(scene2);
    act->add(seq);

    // ---- Move some shots through their lifecycle before we traverse ----
    shotB->advance(); // Scripted -> Shooting (now urgent)

    // ---- Two independent traversals over the same structure ----
    ProductionIterator* full = act->createFullIterator();
    printAll(full, "Full traversal");

    ProductionIterator* urgent = act->createUrgentIterator();
    printAll(urgent, "Urgent-only traversal");

    // ---- Runtime structural change: shotA advances mid-way through, and we
    //      re-run an urgent traversal to show the change is picked up ----
    std::cout << std::endl << "shotA advances (Scripted -> Shooting)..." << std::endl;
    shotA->advance();

    ProductionIterator* urgentAfter = act->createUrgentIterator();
    printAll(urgentAfter, "Urgent-only traversal AFTER change");

    // ---- Decorated unit participating in normal execution ----
    std::cout << std::endl << "Executing the decorated stunt shot:" << std::endl;
    decoratedShotC->execute();

    delete full;
    delete urgent;
    delete urgentAfter;
    delete act; // owns seq -> scenes -> shots (including decoratedShotC), all cleaned up
    return 0;
}