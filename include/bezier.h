#ifndef BEZIER_H
#define BEZIER_H

#include <get_param.h>

class Bezier
{
private:
    Getparam *get_param_;
    double **ctrl_point_;
    double **derivative_ctrl_point_;
    double **double_derivative_ctrl_point_;
    int ctrl_point_num_;
    double Function(const double &t);

public:
    Bezier();
    Bezier(const int line);
    Bezier(const Getparam *get_param);
    ~Bezier();

    void setCtrlPointList(const int n, const double point[][2]);
    double *getLinePoint(const double &t);
    double *getDerivativePoint(const double &t);
    double *getDoubleDerivativePoint(const double &t);
};

#endif // BEZIER_H