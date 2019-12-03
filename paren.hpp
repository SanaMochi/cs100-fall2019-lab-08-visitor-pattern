#ifndef _PAREN_
#define _PAREN_

#include "decorator.hpp"

class Paren: public Decorator{
	Decorator * d;
	public:
	Paren(Decorator* d) : Decorator(d){this->d = d;};
	
	virtual std::string stringify(){
		return "(" + d->c->stringify() + ")";
	}
	virtual Iterator* create_iterator() {
			UnaryIterator* it = new UnaryIterator(this);
			return it;
	}
	void accept(CountVisitor* v) {
			v->visit_paren();
	}
};

#endif	//_PAREN_
