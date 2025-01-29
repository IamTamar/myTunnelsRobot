#include "kalmanFilter.h"

public static double calcKG(double Eest, double Emeas) {
   return (Eest / (Eest + Emeas));
}

//calculate estimation and not error-estimation!
public static double calcEst_t(double Eest_t, double meas_t, , double Emeas_t, double est_t_1) {
	double kg= calcKG(Eest_t, Emeas_t)
	return (est_t_1 + kg*(meas_t- est_t_1))
}


