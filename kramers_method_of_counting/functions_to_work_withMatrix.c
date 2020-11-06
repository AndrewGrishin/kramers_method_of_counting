//
//  hFunctions.c
//  n_rank_definder
//
//  Created on 28/09/2019.
//  Copyright © 2019 All rights reserved.
//

#include "functions_to_work_withMatrix.h"
#include <stdlib.h>

double** createMatrixMemoryAllocation(int strings){
    double **na = (double**)malloc( strings * sizeof(double) );
       for (int i = 0; i < strings; i++) na[i] = (double*)calloc(strings, sizeof(double));
    return na;
}

void cleanMatrix(double **na, int strings){
    for (int i = 0; i < strings; i++) free(na[i]);
    free(na);
}

void cleanArray(double *na, int strings){
    free(na);
}

int numberOfStrings(){
    printf("Input the amount of strings: ");
    int strings = 0;
    scanf("%d", &strings);
    return strings;
}

void printDefinder(double definder){
    if ((int)definder == definder){
        printf("The definder of this matrix is -> %d\n", (int)definder);
    } else {
        printf("The definder of this matrix is -> %.1f\n", definder);
    }
}

void printMatrix(double **na, int strings){
    printf("\n");
    for (int i = 0; i < strings; i++){
        for (int j = 0; j < strings; j++){
            printf("%.1f ", na[i][j]);
        }
        printf("\n");
    }
}

void fillInMatrix(double **na, int strings){
    printf("Input the matrix of indexes.\n");;
    for (int i = 0; i < strings; i++){
        for (int j = 0; j < strings; j++){
            scanf("%lf", &na[i][j]);
        }
    }
}

int inputTheNumberofStrings(){
    printf("Amount of strings/variables: ");
    int strings = 0;
    scanf("%d", &strings);
    return strings;
}

double* createArrayOfAnswerMemoryAllocation(int strings){
    return (double*)calloc(strings, sizeof(double));
}

void fillInArrayOfAnswers(double *na, int strings){
    for (int i = 0; i < strings; i++){
        printf("Input the answer to equation %d: ", i + 1);
        scanf("%lf", &na[i]);
    }
}

void checkAndPrintResults(double *finallArrayWithValuesOfVars, int strings){
    if (finallArrayWithValuesOfVars[0] == 0) {
        printf("Main determinant eqls to %d. Impossible to calculate vars.\n", (int)finallArrayWithValuesOfVars[0]);
    } else {
        if ((int)finallArrayWithValuesOfVars[0] == finallArrayWithValuesOfVars[0]){
            printf("Main det -> %d\n",(int)finallArrayWithValuesOfVars[0]);
        } else {
            printf("Main det -> %.3f\n", finallArrayWithValuesOfVars[0]);
        }
        for (int i = 1; i < strings; i++){
            if (finallArrayWithValuesOfVars[i] == (int)finallArrayWithValuesOfVars[i]){
                printf("x%d eqls to -> %d\n", i ,(int)finallArrayWithValuesOfVars[i]);
            } else {
                printf("x%d eqls to -> %.3f\n", i ,finallArrayWithValuesOfVars[i]);
            }
        }
    }
}
//==================================>
/*
int power(int a, int b){
    if (b == 0) return 1;
    int help = 1;
    for (int i = 0; i < b; i++) help *= a;
    return help;
}*/


/*main functions for calculation
double countDefinderSecondLayer(double **na, int strings, int _i, int _j){
    
    if (strings == 1){
           if (_j == 0) return na[1][1];
           if (_j == 1) return na[1][0];
    }
    
    int helpI = 0;
    int helpJ = 0;
        
        
    double **ba = (double**)malloc( (strings) * sizeof(double) );
    for (int i = 0; i < strings; i++){
        ba[i] = (double*)calloc( (strings), sizeof(double) );
    }
        
    for (int i = 0; i < strings + 1; i++){
        for (int j = 0; j < strings + 1; j++){
            if (i != _i && j != _j){
                ba[helpI][helpJ] = na[i][j];
                helpJ++;
                if (helpJ % strings == 0) {
                    helpI++;
                    helpJ = 0;
                }
            }
        }
    }
    
    double definder = 0;
        
    for (int i = 0; i < strings; i++){
        definder += ba[0][i] * power(-1, i) * countDefinderSecondLayer(ba, strings - 1, 0, i);
    }
        
    return definder;
}

double countDefinder(double **na, int strings){
    double definder = 0;
    
    for (int i = 0; i < strings; i++){
        definder += na[0][i] * power(-1, i) * countDefinderSecondLayer(na, strings - 1, 0, i);
    }
    
    return definder;
}
*/
