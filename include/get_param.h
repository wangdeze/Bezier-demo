#ifndef GETPARAM_H
#define GETPARAM_H

#include <stdio.h>
#include <math.h>

/**获取杨辉三角
 * 
 */
class Getparam
{
private:
    int **params_;
    int line_;

public:
    Getparam(int line);
    Getparam(const Getparam &get_param);
    ~Getparam();
    int GetParam(int m, int n);
};

#endif