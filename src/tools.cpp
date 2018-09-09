#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  // Initialize RMSE vector.
  VectorXd rmse(4);
	rmse << 0,0,0,0;

  unsigned int estimations_size = estimations.size();
  // check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
  if(estimations_size != ground_truth.size()
    || estimations_size == 0){
		cout << "Invalid estimation or ground_truth data" << endl;
		return rmse;
	}

  for(unsigned int i=0; i < estimations_size; ++i){
		VectorXd residual = estimations[i] - ground_truth[i];
    residual = residual.array()*residual.array();
		rmse += residual;
	}

  //calculate the mean
  rmse = rmse/estimations_size;

  //calculate the squared root
  rmse = rmse.array().sqrt();

  //return the result
	return rmse;
}