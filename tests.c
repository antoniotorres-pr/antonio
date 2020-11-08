/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "GuillermoMorel.h"

bool tests()
{
	bool answer = true;
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testEmpty();
	bool ok4 = testRemoveFromList();
	answer =  ok2 && ok3 && ok4;
	return answer;
}


bool testEmpty()
{
	bool ans = true;
	LLNode* emptyList = makeEmptyLinkedList(); //testing if isEmpty() works properly.
	 if( isEmpty(emptyList)){
		 bool ans = true;
	 } else{
		 bool ans = false;
	 }
}

bool testGotAdjacencyMatrix()
{
	bool ans = true;

	return ans;
}

bool testRemoveFromList()
{
	bool ok = true;
	//what are the criteria for success for
	//test case 1:
	//test case 2:

	return ok;
}
