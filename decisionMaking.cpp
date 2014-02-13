#include <iostream>

void decisionMaking()
{
	/*
	 if statement-- checks for a "condition"
									----> asserts an expression as true or false (0 or 1)
	
	expression operators
	====================
	>  [greater than]
	<  [less than]
	>= [greater than or equal]
	<= [less than or equal]
	== [equal]
	!= [not equal]

	logical expression operators
	============================
	&&  AND
	||  OR
	!	NOT
	*/

	if (true || true){ std::cout << "hit the condition: (true || true)";}
	if (true || false){ std::cout << "hit the condition: (true || false)";}
	if (true && true){ std::cout << "hit the condition: (true && true)";}
	if (false && true){ std::cout << "hit the condition: (false || true)";}
	if (!(true || true)){ std::cout << "hit the condition: !(true || true)";}
	if (!(true || false)){ std::cout << "hit the condition: !(true || false)";}
	if (!(false || false)){ std::cout << "hit the condition: !(false || false)";}
}