#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

class Iterator;
class Base {
	
    public:
    Iterator* it;
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */

        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;

		virtual Iterator* create_iterator() = 0;
		Base* get_left(){return this;}
		Base* get_right(){return this;}

};

#endif //__BASE_HPP__
