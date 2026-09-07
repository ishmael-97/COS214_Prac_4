#ifndef PRODUCTIONITERATOR_H
#define PRODUCTIONITERATOR_H

// necessary addtional library
#include <stack>

// dependencies
class ProductionGroup;
class ProductionUnit;
class FullIterator;

class ProductionIterator {
    public:
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() const = 0;
        virtual ProductionUnit* currentItem() const = 0;
        virtual ~ProductionIterator() {}
};

// concrete Iterators #1
class FullIterator : public ProductionIterator {
    public:
        FullIterator(ProductionGroup* root);
        void first() override;
        void next() override;
        bool isDone() const override;
        ProductionUnit* currentItem() const override;
        ~FullIterator() override {}

    private:
        ProductionGroup* root;
        std::stack<ProductionUnit*> traversalStack;
        ProductionUnit* current;
};


// concrete Iterators #2
class UrgentIterator : public ProductionIterator {
    public:
        UrgentIterator(ProductionGroup* root);
        void first() override;
        void next() override;
        bool isDone() const override;
        ProductionUnit* currentItem() const override;
        ~UrgentIterator() override;

    private:
        FullIterator* fullIterator;
        ProductionUnit* current;
};


#endif