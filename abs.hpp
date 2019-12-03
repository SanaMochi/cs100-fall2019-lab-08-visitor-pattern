#ifndef _Abs_
#define _Abs_

#include "decorator.hpp"
#include <cmath>

class Abs : public Decorator {
	public:
	
	Abs(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return std::abs(this->c->evaluate());
	}
	virtual Iterator* create_iterator() {
			UnaryIterator* it = new UnaryIterator(this);
			return it;
	}
	void accept(CountVisitor* v) {
			v->visit_abs();
	}
};

#endif //_Abs_
