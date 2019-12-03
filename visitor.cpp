#include "visitor.hpp"

CountVisitor::CountVisitor(){
	ops = rands = mults = divs = add = sub = pow = ceil = floor = abs = trunc = paren = 0;
}

void CountVisitor::visit_op() {this->ops++;}
int CountVisitor::op_count(){return ops;}
        

