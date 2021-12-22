#include <simpson.h>

Simpson::Simpson()
    : count_(0)
{
}

Simpson::~Simpson()
{
}

double Simpson::getSimpson(const double &floor, const double &top)
{
    double mid = 0.5 * (floor + top);
    double ret = ((top - floor) * (Func_(floor) + Func_(top) + (4 * Func_(mid)))) / 6;
    return ret;
}

double Simpson::Slove(const double &floor, const double &top)
{
    count_ ++;
    double mid = 0.5 * (floor + top);
    double sum = getSimpson(floor, top);
    double floor_half = getSimpson(floor, mid);
    double top_half = getSimpson(mid, top);
    double error = sum - (floor_half + top_half);
    if (error > error_threshold && count_ < times_threshold)
    {
        sum = Slove(floor, mid) + Slove(mid, top);
    }
    return sum;
}