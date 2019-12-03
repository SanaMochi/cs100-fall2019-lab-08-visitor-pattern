#ifndef __OP_HPP__
#define __OP_HPP__

#include <string>
#include "base.hpp"
#include "visitor.hpp"

class Op : public Base {
	double Value;
	//UnaryIterator* uIt;
    public:
        Op(double value) : Base() { Value = value; }
        virtual double evaluate() { return Value; }
        virtual std::string stringify() { return std::to_string(Value); }
        Iterator* create_iterator(){ i = new UnaryIterator(this); return i; }
        void accept(CountVisitor * v){	v->visit_op();	}
};

#endif //__OP_HPP__
