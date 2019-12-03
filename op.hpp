#ifndef __OP_HPP__
#define __OP_HPP__

#include <string>
#include "base.hpp"

class Op : public Base {
	double Value;
    public:
        Op(double value) : Base() { Value = value; }
        virtual double evaluate() { return Value; }
        virtual std::string stringify() { return std::to_string(Value); }
        virtual Iterator* create_iterator() {
			it = new UnaryIterator(this);
			return it;
		}
		void accept(CountVisitor* v) {
			v->visit_op();
		}
};

#endif //__OP_HPP__
