#include "ProductionUnit.h"
#include "ProductionGroup.h"
#include "ProductionIterator.h"
#include "Shot.h"
#include "PriorityDecorator.h"
#include "InsuranceDecorator.h"
#include <iostream>

int printAll(ProductionIterator* it, const std::string& label) {
    std::cout << "--- " << label << " ---" << std::endl;
    int count = 0;
    for (it->first(); !it->isDone(); it->next()) {
        ProductionUnit* unit = it->currentItem();
        std::cout << unit->getStatus() << (unit->isUrgent() ? "  (URGENT)" : "") << std::endl;
        count++;
    }
    return count;
}

int main() {
    // ---- Build a 3-level nested hierarchy: Act -> Sequence -> Scene -> Shot ----
    Act* act = new Act("Act 1");
    Sequence* seq = new Sequence("Opening Sequence");
    Scene* scene1 = new Scene("Rooftop Scene");
    Scene* scene2 = new Scene("Car Chase Scene");

    Shot* shotA = new Shot("Wide establishing shot");
    Shot* shotB = new Shot("Close-up on Hero");
    Shot* shotC = new Shot("Stunt jump");

    scene1->add(shotA);
    scene1->add(shotB);

    ProductionUnit* decoratedShotC = new PriorityDecorator(new InsuranceDecorator(shotC, 500000.0));
    scene2->add(decoratedShotC);

    seq->add(scene1);
    seq->add(scene2);
    act->add(seq);

    shotB->advance();

    std::cout << "== Morning production meeting: reviewing today's full schedule ==" << std::endl;
    ProductionIterator* full = act->createFullIterator();
    int fullCount = printAll(full, "Full traversal");                          

    ProductionIterator* urgent = act->createUrgentIterator();
    int urgentCount = printAll(urgent, "Urgent-only traversal");               
    std::cout << urgentCount << " of " << fullCount 
    << " things in the schedule need attention "
    << "(groups and shots alike)." << std::endl;

    std::cout << std::endl << "== Schedule has shifts: the establishing shot is being filmed earlier == " << std::endl;
    shotA->advance();

    ProductionIterator* urgentAfter = act->createUrgentIterator();
    int urgentAfterCount = printAll(urgentAfter, "Urgent-only traversal AFTER change");   // optional, same pattern
    std::cout << urgentAfterCount << " urgent after the schedule change." << std::endl;    // optional

    std::cout << std::endl << "== Wrapping the day: the insured stunt jump goes ahead ==" << std::endl;
    decoratedShotC->execute();

    delete full;
    delete urgent;
    delete urgentAfter;
    delete act;
    return 0;
}