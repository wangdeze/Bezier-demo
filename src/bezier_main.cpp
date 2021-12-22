#include <get_param.h>
#include <simpson.h>
#include <bezier.h>

#include <stdio.h>
#include <math.h>

Bezier *bezier_;
Simpson simpson_;

double Function(double t)
{
    double dx = bezier_->getDerivativePoint(t)[0];
    double dy = bezier_->getDerivativePoint(t)[1];
    double double_dis = std::pow(dx, 2) + std::pow(dy,2);
    return std::sqrt(double_dis);
}

int main()
{
    bezier_ = new Bezier(15);
    printf("start, set point list\n");
    double point_list[10][2];
    point_list[0][0] = -2.0553;
    point_list[0][1] = 0.0627;
    point_list[1][0] = -0.0143;
    point_list[1][1] = 0.059;
    point_list[2][0] = -1.8058;
    point_list[2][1] = 0.0;
    point_list[3][0] = -1.3;
    point_list[3][1] = 0.0;
    point_list[4][0] = 2.0;
    point_list[4][1] = 0.0;
    point_list[5][0] = 3.0;
    point_list[5][1] = 3.0;
    int point_list_size = 3;
    printf("set bezier point list\n");
    bezier_->setCtrlPointList(point_list_size, point_list);
    printf("set simpson\n");
    simpson_.setError(0.1);
    simpson_.setFunction(Function);
    simpson_.setTimes(10);
    printf("calculate bezier line\n");
    for (double t = 0; t <= 1.01; t += 0.005)
    {
        printf("t: %f\n", t);
        double *P;
        P = bezier_->getLinePoint(t);
        printf("Line: %f, %f\n", P[0], P[1]);

        double *dP;
        dP = bezier_->getDerivativePoint(t);
        printf("Derivative: %f, %f\n", dP[0], dP[1]);
        double k = dP[0] / dP[1];
        double angle = atan2(dP[1], dP[0]);
        printf("ak = %f\nangle = %f\n", k, (angle / M_PI) * 180);
        // Point(t, 1, &ddx, &ddy, ddx_, ddy_);
        double *ddP;
        ddP = bezier_->getDoubleDerivativePoint(t);
        printf("SecondDerivative: %f, %f\n", ddP[0], ddP[1]);
        double K = std::fabs((dP[0] * ddP[1]) - (dP[1] * ddP[0])) / std::pow((std::pow(dP[0], 2) + std::pow(dP[1], 2)), (3.0 / 2.0));
        printf("dk = %f\n", K);
        double line_long = simpson_.Slove(0, t);
        printf("line long = %f\n", line_long);
    }
    delete bezier_;
}