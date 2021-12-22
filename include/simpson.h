#ifndef SIMPSON_H
#define SIMPSON_H

#include <stdio.h>
#include <math.h>

/**Simpson数值积分
 * 
 */
class Simpson
{
private:
    double (*Func_)(double);
    double error_threshold;
    int times_threshold;
    int count_;
public:
    Simpson();
    ~Simpson();

    double getSimpson(const double &floor, const double &top);
    double Slove(const double &floor, const double &top);
    // 设置被积函数
    void setFunction(double (*Func)(double)) { Func_ = Func; }
    // 设置积分终止误差
    void setError(const double &error) { error_threshold = error; }
    // 设置迭代终止次数
    void setTimes(const int &times) { times_threshold = 2 * times - 1; }
};

#endif