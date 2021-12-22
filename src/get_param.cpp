#include <get_param.h>

/**
 * @param line 杨辉三角阶数
 */
Getparam::Getparam(int line) : line_(line)
{
    params_ = new int *[line_];
    for (int i = 0; i < line_; i++)
    {
        params_[i] = new int[line_];
    }

    for (int i = 0; i < line_; i++)
    {
        params_[i][0] = 1;
        params_[i][i] = 1;
    }
    for (int i = 1; i < line_; i++)
    {
        for (int j = 0; j < i; j++)
        {
            params_[i][j] = params_[i - 1][j - 1] + params_[i - 1][j];
        }
    }
}

Getparam::~Getparam()
{
    for (int i = 0; i < line_; i++)
    {
        delete[] params_[i];
    }
    delete[] params_;
}

/**返回杨辉三角第m行第n列的值
 */
int Getparam::GetParam(int m, int n)
{
    if (m < line_ && n < line_)
    {
        return params_[m][n];
    }
    return -1;
}