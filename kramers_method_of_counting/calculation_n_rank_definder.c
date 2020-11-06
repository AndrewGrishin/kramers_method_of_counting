//
//  calculation_n_rank_definder.c
//  kramers_method_of_counting
//
//  Created on 02/10/2019.
//  Copyright © 2019 All rights reserved.
//

#include "calculation_n_rank_definder.h"

#include <stdio.h>
#include <stdlib.h>

/*main functions for calculation*/

int power(int a, int b){
    if (b == 0) return 1;
    int help = 1;
    for (int i = 0; i < b; i++) help *= a;
    return help;
}

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

double helpfulMatrixCreation(double **na, double *answers, int strings, int index){
    
    double **ba = (double**)malloc(strings * sizeof(double));
    
    for (int i = 0; i < strings; i++){
        ba[i] = (double*)calloc(strings, sizeof(double));
        for (int j = 0; j < strings; j++){
            ba[i][j] = na[i][j];
        }
    }
    
    for (int i = 0; i < strings; i++){
        ba[i][index] = answers[i]; 
    }
    
    return countDefinder(ba, strings);
    
}

double* kramersCount(double **na, double *answers, int strings){
    
    double* finalAnswers = (double*)calloc(strings + 1, sizeof(double));
    
    finalAnswers[0] = countDefinder(na, strings);
    
    if (finalAnswers[0] == 0) return finalAnswers;
    
    for (int i = 1; i <= strings; i++){
        finalAnswers[i] = helpfulMatrixCreation(na, answers, strings, i - 1) / finalAnswers[0];
    }
    return finalAnswers;
}
