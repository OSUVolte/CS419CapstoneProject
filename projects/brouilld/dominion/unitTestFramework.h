#ifndef _UNIT_TEST_FRAMEWORK_H
#define _UNIT_TEST_FRAMEWORK_H

void TestSuite(void(*toRun)(), char testName[]);
void testInfoOutput(char testName[80], char testInfo[]);
void assertTest(void *given, void *expected, char info[]);
void testPass(char info[]);
void testFail(char info[], void *given, void *expected);
void testSeparate();
void outputResults();


#endif
