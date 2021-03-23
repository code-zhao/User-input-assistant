 ///
 /// @file    gen.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-01-15 18:36:22
 ///

#include "Dict.h"
#include <iostream>
using std::cout;
using std::endl;
 
void test()
{
	Dict mydict("./lib/", "../data/");
	mydict.genEn();
	mydict.genCN();
	mydict.output();
	cout << "successfully" << endl;
}

int main(void)
{
	test();
	return 0;
}
