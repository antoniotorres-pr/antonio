/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include "GuillermoMorel.h"


bool production(int argc, char* argv[])
{
	bool answer = true;

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		int maxRooms;
		int maxTreasure;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
			switch(i)
			{
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of rooms

				aL= strtol(argv[i], &eptr, 10);
				maxRooms = (int) aL;
				if(maxRooms <0)
				{
					answer = false;
				}
				printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
				break;
			case 3:
				//this is maximum amount of treasure

				aL= strtol(argv[i], &eptr, 10);
				maxTreasure = (int) aL;
				if(maxTreasure <0)
				{
					answer = false;
				}
				printf("Amount of treasure is %d\n",maxTreasure);fflush(stdout);
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);

	}//end of command line arguments

	//obtain space for 20x20 of integers

	int* theSpaceP = (int*) malloc(20*20*sizeof(int));
    bool okInit = initSpace(theSpaceP, 20);
    if (okInit)
    {
    	puts("Array successfully initiazed");
    }
    else
    {
    	puts("Array failed to initialize");
    }
    srand(time(0)); //random seed
    LLNode* linkedList = makeEmptyLinkedList();
    int largestValue = 42;
    	for (int i = 1; i < largestValue; i++)
    	{
    		markerPlacer(i,theSpaceP,linkedList);
    	}
    printHistory(linkedList);
    arrayBoard(theSpaceP);

	//we'll want to read the file
	return answer;
}

void markerPlacer(int i, int* array, LLNode* linkedListNode)
{
	//random value for row/col from 0 to 19
	int row = (rand() % 20);
	int col = (rand() % 20);
	Marker* markerP = placeMarker(row,col);
	markerP->index = i;
	savePayload(linkedListNode, markerP);
	*(array + (row*20) + col) = i;
}

void arrayBoard(int* arrayP){
	#define value -1
	int valuePlaceholder = value;
	for (int i = 0; i <20; i++)
	{
		for (int j = 0; j <20; j++)
		{
			valuePlaceholder = *(arrayP+(i*20) + j);
			valuePlaceholder = valuePlaceholder % 10;
			printf("%d ", valuePlaceholder);
			printf(" ");
		}
		printf("\n");
		}
	}

