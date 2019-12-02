#ifndef _TRUNC_
#define _TRUNC_

#include "decorator.hpp"
#include <iostream>

class Trunc: public Decorator{
	public:
	//std::string string;
	Base* Oprand1;
	Decorator* d;
	
	Trunc(Decorator* d) : Decorator(d){
		this->d = d;
		parse(d->stringify());
		};
	void parse(std::string string){
		int num1, num2, at;
		if(string.find("+") != -1){
			at = string.find("+");
			num1 = std::stoi(string.substr(0, at));
			num2 = std::stoi(string.substr(at+1, string.size()));
			Oprand1 = new Op(num1 + num2);
			this->d->c = Oprand1;
		}else{
			at = string.find("-");
			num1 = std::stoi(string.substr(0, at));
			num2 = std::stoi(string.substr(at+1, string.size()));
			Oprand1 = new Op(num1 - num2);
			this->d->c = Oprand1;
		}
		
	}
	
	virtual std::string stringify(){
		return Oprand1->stringify();
	}
	virtual Iterator* create_iterator() {
			UnaryIterator* it = new UnaryIterator(this);
			return it;
	}
};

#endif	//_TRUNC_
