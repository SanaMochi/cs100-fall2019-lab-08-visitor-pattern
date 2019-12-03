#include "gtest/gtest.h"
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(IteratorTest, OpTest){
	Op* op = new Op(2);
	Iterator* it = op->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 2);
}

TEST(IteratorTest, AddTest){
	Op* op1 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op1, op2);
	Iterator* it = add->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 6);
}

TEST(IteratorTest, SubTest){
	Op* op1 = new Op(10);
	Op* op2 = new Op(5);
	Sub* sub = new Sub(op1, op2);
	Iterator* it = sub->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 5);
}

TEST(IteratorTest, MultTest){
	Op* op1 = new Op(4);
	Op* op2 = new Op(2);
	Mult* mult = new Mult(op1, op2);
	Iterator* it = mult->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 8);
}

TEST(IteratorTest, DivTest){
	Op* op1 = new Op(20);
	Op* op2 = new Op(2);
	Div* div = new Div(op1, op2);
	Iterator* it = div->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 10);
}

TEST(IteratorTest, CeilingTest){
	Op* op = new Op(6.4);
	Ceiling* ceiling = new Ceiling(op);
	Iterator* it = ceiling->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 7);
}

TEST(IteratorTest, FloorTest){
	Op* op = new Op(6.4);
	Floor* floor = new Floor(op);
	Iterator* it = floor->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 6);
}

TEST(IteratorTest, AbsTest){
	Op* op = new Op(-9);
	Abs* abs = new Abs(op);
	Iterator* it = abs->create_iterator();
	EXPECT_EQ(it->current()->evaluate() , 9);
}

TEST(IteratorTest, TruncTest){
	Op* op1 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op1, op2);
	Decorator* dec = new Decorator(add);
	Trunc* tr = new Trunc(dec);
	Iterator* it = tr->create_iterator();
	EXPECT_EQ(it->current()->stringify() , "6.000000");
}

TEST(IteratorTest, ParenTest){
	Op* op1 = new Op(4);
	Op* op2 = new Op(2);
	Sub* sub = new Sub(op1, op2);
	Decorator* dec = new Decorator(sub);
	Paren* p = new Paren(dec);
	Iterator* it = p->create_iterator();
	EXPECT_EQ(it->current()->stringify() , "(4.000000 - 2.000000)");
}
/*
TEST(VisitorTest, Test1){
	Op* op1 = new Op(4);
	Op* op2 = new Op(2);
	Sub* sub = new Sub(op1, op2);
	Paren* p = new Paren(dec);
	Iterator* it = p->create_iterator();
}
*/
