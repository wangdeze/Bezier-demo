#include <bezier.h>

Bezier::Bezier()
    : ctrl_point_num_(0)
{
}
Bezier::Bezier(const int param_line)
    : ctrl_point_num_(0)
{
    get_param_ = new Getparam(param_line);
}

Bezier::~Bezier()
{
    delete get_param_;
    if (ctrl_point_num_ > 0)
    {
        for (int i = 0; i < ctrl_point_num_ + 1; i++)
        {
            delete[] ctrl_point_[i];
        }
        delete[] ctrl_point_;
        for (int i = 0; i < ctrl_point_num_; i++)
        {
            delete[] derivative_ctrl_point_[i];
        }
        delete[] derivative_ctrl_point_;
        if (ctrl_point_num_ - 1 > 0)
        {
            for (int i = 0; i < ctrl_point_num_ - 1; i++)
            {
                delete[] double_derivative_ctrl_point_[i];
            }
            delete[] double_derivative_ctrl_point_;
        }
    }
}

void Bezier::setCtrlPointList(const int n, const double point[][2])
{
    ctrl_point_num_ = n;
    ctrl_point_ = new double *[ctrl_point_num_ + 1];
    derivative_ctrl_point_ = new double *[ctrl_point_num_];
    double_derivative_ctrl_point_ = new double *[ctrl_point_num_ - 1];
    printf("set line ctrl point\n");
    for (int i = 0; i < ctrl_point_num_ + 1; i++)
    {
        ctrl_point_[i] = new double[2];
        ctrl_point_[i][0] = point[i][0]; // point_x
        ctrl_point_[i][1] = point[i][1]; // point_y
    }
    printf("set derivative point\n");
    for (int i = 0; i < ctrl_point_num_; i++)
    {
        derivative_ctrl_point_[i] = new double[2];
        derivative_ctrl_point_[i][0] = ctrl_point_num_ * (ctrl_point_[i + 1][0] - ctrl_point_[i][0]);
        derivative_ctrl_point_[i][1] = ctrl_point_num_ * (ctrl_point_[i + 1][1] - ctrl_point_[i][1]);
    }
    printf("set double derivative point\n");
    for (int i = 0; i < ctrl_point_num_ - 1; i++)
    {
        double_derivative_ctrl_point_[i] = new double[2];
        double_derivative_ctrl_point_[i][0] = (ctrl_point_num_ - 1) * (derivative_ctrl_point_[i + 1][0] - derivative_ctrl_point_[i][0]);
        double_derivative_ctrl_point_[i][1] = (ctrl_point_num_ - 1) * (derivative_ctrl_point_[i + 1][1] - derivative_ctrl_point_[i][1]);
    }
}

double *Bezier::getLinePoint(const double &t) {
    double * ret = new double[2];
    ret[0] = 0;
    ret[1] = 0;
    for (int i = 0; i <= ctrl_point_num_; i++)
    {
        int param = get_param_->GetParam(ctrl_point_num_, i);
        ret[0] += (double)param * std::pow((1 - t), (ctrl_point_num_ - i)) * std::pow(t, i) * ctrl_point_[i][0];
        ret[1] += (double)param * std::pow((1 - t), (ctrl_point_num_ - i)) * std::pow(t, i) * ctrl_point_[i][1];
    }
    return ret;
}

double *Bezier::getDerivativePoint(const double &t) {
    double * ret = new double[2];
    ret[0] = 0;
    ret[1] = 0;
    for (int i = 0; i <= ctrl_point_num_ - 1; i++)
    {
        int param = get_param_->GetParam(ctrl_point_num_ - 1, i);
        ret[0] += (double)param * std::pow((1 - t), (ctrl_point_num_ - 1 - i)) * std::pow(t, i) * derivative_ctrl_point_[i][0];
        ret[1] += (double)param * std::pow((1 - t), (ctrl_point_num_ - 1 - i)) * std::pow(t, i) * derivative_ctrl_point_[i][1];
    }
    return ret;
}
double *Bezier::getDoubleDerivativePoint(const double &t) {
    double * ret = new double[2];
    ret[0] = 0;
    ret[1] = 0;
    for (int i = 0; i <= ctrl_point_num_ - 2; i++)
    {
        int param = get_param_->GetParam(ctrl_point_num_ - 2, i);
        ret[0] += (double)param * std::pow((1 - t), (ctrl_point_num_ - 2 - i)) * std::pow(t, i) * double_derivative_ctrl_point_[i][0];
        ret[1] += (double)param * std::pow((1 - t), (ctrl_point_num_ - 2 - i)) * std::pow(t, i) * double_derivative_ctrl_point_[i][1];
    }
    return ret;
}