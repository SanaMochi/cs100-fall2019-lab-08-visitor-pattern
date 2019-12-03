#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;
        
        int ceil;
        int floor;
        int abs;
        int trunc;
        int paren;

    public:
        CountVisitor(){}

        void visit_op() {this->ops++;}
        int op_count() {return ops;}
        void visit_rand() {this->rands++;}
        int rand_count() {return rands;}
        void visit_mult() {this->mults++;}
        int mult_count() {return mults;}
        void visit_div() {this->divs++;}
        int div_count() {return divs;}
        void visit_add() {this->add++;}
        int add_count() {return add;}
        void visit_sub() {this->sub++;}
        int sub_count() {return sub;}
        void visit_pow() {this->pow++;}
        int pow_count() {return pow;}

        void visit_ceil() {this->ceil++;}
        int ceil_count() {return ceil;}
        void visit_floor() {this->floor++;}
        int floor_count() {return floor;}
        void visit_abs() {this->abs++;}
        int abs_count() {return abs;}
        void visit_trunc() {this->trunc++;}
        int trunc_count() {return trunc;}
        void visit_paren() {this->paren++;}
        int paren_count() {return paren;}
};

#endif //__COUNT_VISITOR_HPP__
