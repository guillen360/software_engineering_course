/*
pre-processor directives
========================
if condition "#ifndef" and "#ifdef" 
to conditionally load function prototypes and
other pre-processor stuff
--- don't want to import things twice! compiler error will occur
*/

#ifndef _SIMPLE_MATH_H_
#define _SIMPLE_MATH_H_

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);

#endif