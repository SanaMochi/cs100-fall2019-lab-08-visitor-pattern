#include "base.hpp"
#include "op.hpp"
#include "iterator.hpp"
#include "add.hpp"
#include <iostream>
#include <string>

int main (){
	Op* one = new Op(1);
	Iterator* it = one->create_iterator();
	std::cout << it->current()->evaluate() << std::endl;
	Op* two = new Op(2);
	it->next();
	it = two->create_iterator();
	std::cout << it->current()->evaluate() << std::endl;
	it->next();
	if(it->is_done())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	//Iterator* it2 = two->create_iterator();
	//std::cout << it2->current()->evaluate() << std::endl;
	Add* add = new Add(one, two);
	Iterator* binit  =add->create_iterator();
	std::cout << binit->current()->evaluate() << std::endl;
	return 0;
}
