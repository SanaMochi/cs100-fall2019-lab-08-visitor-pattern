#ifndef __DEC_HPP__
#define __DEC_HPP__

#include "base.hpp"
#include "iterator.hpp"

class Decorator: public Base{
	protected:
	
	
	public:
	Base* c;
	Decorator(Base* b){this->c = b;}
	
	virtual double evaluate(){
		return this->c->evaluate();
	}
	
    virtual std::string stringify(){
		return this->c->stringify();
	}
	virtual Iterator* create_iterator() {}
	Decorator* get_left(){return this;}
	Decorator* get_right(){return this;}
};
#endif
