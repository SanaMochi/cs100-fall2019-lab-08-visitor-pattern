#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
	Base* Oprand1;
	Base* Oprand2;
    public:
        Sub(Base* Op1, Base* Op2 ) : Base() { Oprand1 = Op1; Oprand2 = Op2;}
        virtual double evaluate() { return (Oprand1->evaluate() - Oprand2->evaluate());}
        virtual std::string stringify() { return std::to_string(Oprand1->evaluate()) + " - " + std::to_string(Oprand2->evaluate()); }
        virtual Iterator* create_iterator() {
			BinaryIterator* it = new BinaryIterator(this);
			return it;
		}
};

#endif //__RAND_HPP__
