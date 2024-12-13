#include <vector>
#include <thread>

double trapezoid_area(double (*f)(double), double a, double b, int n);

void compute_area(double (*f)(double), double a, double b, int n, unsigned int thread_id, unsigned int num_threads, double &result);
