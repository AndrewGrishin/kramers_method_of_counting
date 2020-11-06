//
//  main.c
//  kramers_method_of_counting
//
//  Created on 02/10/2019.
//  Copyright © All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions_to_work_withMatrix.h"
#include "calculation_n_rank_definder.h"

void start(){
    int strings = inputTheNumberofStrings();
    double **na = createMatrixMemoryAllocation(strings);
    double *answers = createArrayOfAnswerMemoryAllocation(strings);
    fillInMatrix(na, strings);
    fillInArrayOfAnswers(answers, strings);
    double *finallArrayWithValuesOfVars = kramersCount(na, answers, strings);
    checkAndPrintResults(finallArrayWithValuesOfVars, strings + 1);
    
    cleanMatrix(na, strings);
    cleanArray(answers, strings);
    cleanArray(finallArrayWithValuesOfVars, strings + 1);
}

int main(int argc, const char * argv[]) {
    
    start();
    
    return 0;
}
