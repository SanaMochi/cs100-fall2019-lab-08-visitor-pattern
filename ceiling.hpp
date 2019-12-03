#ifndef _Ceiling_
#define _Ceiling_

#include "decorator.hpp"
#include <cmath>

class Ceiling : public Decorator {
	public:
	Ceiling(Base* c) : Decorator(c){
		this->c = c;
	}
	
	virtual double evaluate() {
		return ceil(this->c->evaluate());
	}
	virtual Iterator* create_iterator() {
			UnaryIterator* it = new UnaryIterator(this);
			return it;
	}
	void accept(CountVisitor* v) {
			v->visit_ceil();
	}
};

#endif //_Ceiling_
