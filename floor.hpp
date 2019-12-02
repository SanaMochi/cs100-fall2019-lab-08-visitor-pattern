#ifndef _Floor_
#define _Floor_

#include "decorator.hpp"
#include <cmath>

class Floor : public Decorator {
	public:
	
	Floor(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return floor(this->c->evaluate());
	}
	virtual Iterator* create_iterator() {
			UnaryIterator* it = new UnaryIterator(this);
			return it;
	}
};

#endif //_Floor_
