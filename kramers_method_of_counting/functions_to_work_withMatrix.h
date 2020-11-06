//
//  hFunctions.h
//  n_rank_definder
//
//  Created on 28/09/2019.
//  Copyright © 2019 All rights reserved.
//

#ifndef hFunctions_h
#define hFunctions_h

#include <stdio.h>

double** createMatrixMemoryAllocation(int strings);
void cleanMatrix(double **na, int strings);
void cleanArray(double *na, int strings);
int numberOfStrings(void);
void printDefinder(double definder);
void printMatrix(double **na, int strings);
void fillInMatrix(double **na, int strings);
void fillInArrayOfAnswers(double *na, int strings);
int inputTheNumberofStrings(void);
double* createArrayOfAnswerMemoryAllocation(int strings);
void checkAndPrintResults(double* finallArrayWithValuesOfVars, int strings);
//int power(int a, int b);
//double countDefinderSecondLayer(double **na, int strings, int _i, int _j);
//double countDefinder(double **na, int strings);

#endif /* hFunctions_h */
