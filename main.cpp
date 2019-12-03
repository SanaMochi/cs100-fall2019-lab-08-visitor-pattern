#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "add.hpp"
#include "visitor.hpp"
#include <iostream>
#include <string>

int main (){
	Op* one = new Op(1);
	Op* two = new Op(2);
	PreorderIterator* it = new PreorderIterator(one);
	CountVisitor* v = new CountVisitor();
	
	it = (PreorderIterator*)one->create_iterator();
	std::cout << it->current()->evaluate() << std::endl;
	it->next();
	it = (PreorderIterator*)two->create_iterator();
	std::cout << it->current()->evaluate() << std::endl;
	//it->next();
	//it = (PreorderIterator*)one->create_iterator();
	//std::cout << it->current()->evaluate() << std::endl;
	
	while(!it->is_done()){
		one->accept(v);
		it->next();
	}
	
	std::cout << "Number: " << v->op_count() << std::endl;
	
	/*
	Op* two = new Op(2);
	it->next();
	it = two->create_iterator();
	std::cout << it->current()->evaluate() << std::endl;
	if(it->is_done())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	//Iterator* it2 = two->create_iterator();
	//std::cout << it2->current()->evaluate() << std::endl;
	it->first();
	/*
	while(!it->is_done()){
		op->accept(v);
		it->next();
	}
	std::cout << "\nOPs: " << v->op_count();*/
	return 0;
}
