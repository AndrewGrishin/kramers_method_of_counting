//
//  calculation_n_rank_definder.h
//  kramers_method_of_counting
//
//  Created by Андрей Гришин on 02/10/2019.
//  Copyright © 2019 Андрей Гришин. All rights reserved.
//

#ifndef calculation_n_rank_definder_h
#define calculation_n_rank_definder_h

#include <stdio.h>
#include <stdlib.h>

int power(int a, int b);
double countDefinderSecondLayer(double **na, int strings, int _i, int _j);
double countDefinder(double **na, int strings);
double* kramersCount(double **na, double *answers, int strings);
#endif /* calculation_n_rank_definder_h */
