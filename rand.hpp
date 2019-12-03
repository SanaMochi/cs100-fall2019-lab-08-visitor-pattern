#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <stdlib.h>

class Rand : public Base {
	double value = rand() % 100;
    public:
        Rand() : Base() { }
        virtual double evaluate() { return value; }
        virtual std::string stringify() { return std::to_string(value); }
		virtual Iterator* create_iterator() {
			it = new UnaryIterator(this);
			return it;
		}
		void accept(CountVisitor* v) {
			v->visit_rand();
		}
};

#endif //__RAND_HPP__
