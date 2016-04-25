#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "unitTestFramework.h"

#define PASS "\x1B[32m"
#define FAIL "\x1B[31m"
#define NORMALTEXT "\x1B[0m"


void TestSuite(void (*toRun)(), char testName[])
{
	testSeparate();

	testInfoOutput(testName, "BEGIN");

	toRun();

	testInfoOutput(testName, "END");

	testSeparate();
}


void testInfoOutput(char testName[], char testInfo[])
{
	printf("\n\n");
	printf("    Unit Test: %s\n", testName);
	printf("    %s\n", testInfo);
	printf("\n\n");

	FILE *doc = fopen("unittestresults.out", "a");
	fprintf(doc, "\n\n");
	fprintf(doc, "    Unit Test: %s\n", testName);
	fprintf(doc, "    %s\n", testInfo);
	fprintf(doc, "\n\n");
	fclose(doc);
}

//void beforeTest(void(*toRun)(), int numberOfTimes, ...)
//{
//	int i;
//	va_list funcArgs;
//	va_start(funcArgs, numberOfTimes);
//
//	for (i = 0; i < numberOfTimes; i++)
//	{
//
//		toRun(__VA_ARGS__);
//	}
//
//}


void assertTest(void *given, void *expected, char info[])
{
	if (given == expected)
	{
		testPass(info);
	}
	else
	{
		testFail(info, given, expected);
		
	}
}

void testPass(char info[])
{
	printf("        %s+ PASS : %s %s\n", PASS, info, NORMALTEXT);
	
	FILE *doc = fopen("unittestresults.out", "a");
	fprintf(doc, "        + PASS : %s\n", info);
	fclose(doc);
}

void testFail(char info[], void *given, void *expected)
{
	printf("        %s- FAIL : %s %s\n", FAIL, info, NORMALTEXT);
	printf("               %sResult was %i. Expected %i %s\n", FAIL, given, expected, NORMALTEXT);
	
	FILE *doc = fopen("unittestresults.out", "a");
	fprintf(doc, "        - FAIL : %s\n", info);
	fprintf(doc, "               Result was %i. Expected %i \n", given, expected);
	fclose(doc);
}

void testSeparate()
{
	printf("    %s-------------------------------------------------------------%s\n", PASS, NORMALTEXT);
	FILE *doc = fopen("unittestresults.out", "a");
	fprintf(doc, "    -------------------------------------------------------------\n");
	fclose(doc);

}
