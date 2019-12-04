#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "decorator.hpp"
#include "ceiling.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include "iterator.hpp"

int main(){
	Op* one = new Op(1);
	Op* five = new Op(5);
	Add* sum = new Add(one, five);
	CountVisitor* v = new CountVisitor();
	PreorderIterator* i = new PreorderIterator(sum);
	std::cout << i->current() << std::endl;
	i->next();/*
	i = new PreorderIterator(one);
	std::cout << i->current() << std::endl;
	i->next();
	i = new PreorderIterator(five);
	std::cout << i->current() << std::endl;
	*/
	/*
	sum->accept(v);
	while(!i->is_done()){
		sum->accept(v);
		i->next();
	}*/
	return 0;
}
