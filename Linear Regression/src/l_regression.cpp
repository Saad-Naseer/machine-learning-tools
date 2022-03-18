#include <iostream>
#include <fstream>
#include "matplotlibcpp.h"
#include <eigen3/Eigen/Dense>
namespace plt = matplotlibcpp;
int main(int argc, char *argv[])
{
    Eigen::VectorXf data_x;
    Eigen::VectorXf data_y;

    std::ifstream infile;
    infile.open("/home/robidia/machine-learning-tools/Linear Regression/src/dataset.txt"); // contains two columns [x y]
    if (infile.fail())
    {
        std::cout << "error not found file" << std::endl;
        return 1;
    }
    float f_x = 0;
    float f_y = 0;
    int i = 0;
    while (infile >> f_x >> f_y) 
    {

        data_x.conservativeResize(i + 1);
        data_y.conservativeResize(i + 1);
        data_x[i] = f_x;
        data_y[i] = f_y;
        std::cout << data_x[i] << "  " << data_y[i] << std::endl;
        i++;
    }
   
    infile.close();
    // plot data
    // plt::figure();
    std::cout << data_x.size();
    plt::plot(data_x, data_y, "r*");
    plt::xlabel("x");
    plt::ylabel("y");
    // plt::show();
    // plt::plot({1,3,2,4});
    //plt::show();

    // obs vector
    Eigen::VectorXf obs;
    obs.resize(data_y.size());
    for (int i = 0; i < data_y.size(); i++)
    {
        obs[i] = data_y[i];
    }
    // unkonwn vector
    Eigen::Vector2f unknown;
    // find redundancy
    int redundancy = obs.size() - unknown.size();
    // design matrix
    Eigen::MatrixXf design_mat(obs.size(), unknown.size());
    for (int i = 0; i < obs.size(); i++)
    {
        design_mat(i, 0) = data_x[i];
        design_mat(i, 1) = 1;
    }
    // covariance matrix (error in obs)
    Eigen::MatrixXf cov(obs.size(), obs.size());
    cov.setIdentity();
    // use least square equation
    unknown = (design_mat.transpose() * cov.inverse() * design_mat).inverse() * design_mat.transpose() * cov.inverse() * obs;
    std::cout << "unknown parameters : " << unknown << std::endl;
    Eigen::VectorXf linespace(10);
    for (int i = 0; i < linespace.size(); i++)
    {
        linespace(i) =  1.5*i;
    }
    Eigen::VectorXf y(linespace.size());
    y = unknown[0] * linespace;
    y.array() += unknown[1];
     plt::plot(linespace, y);
     plt::show();

    return 0;
}
