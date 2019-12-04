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
	i->first();
	i->next();
	i = (PreorderIterator*)sum->create_iterator();
	std::cout << i->current()->evaluate() << std::endl;
	i = (PreorderIterator*)one->create_iterator();
	std::cout << i->current()->evaluate() << std::endl;
	//i->first();
	i->next();
	i = (PreorderIterator*)five->create_iterator();
	std::cout << i->current()->evaluate() << std::endl;
	
	/*
	sum->accept(v);
	while(!i->is_done()){
		sum->accept(v);
		i->next();
	}*/
	return 0;
}
