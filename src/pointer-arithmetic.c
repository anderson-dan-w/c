#include <stdio.h>

const static double my_doubles[] = {
    1.0, 2.0, 3.0, 4.0, 5.0, 0.0
};

const static double other_doubles[] = {
    100.0, 200.0, 300.0, 400.0, 500.0, 600.0, 700.0, 800.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

double safe_sum(const double* values) {
    double sum = 0.0;
    while (*values) {
        sum += *values++;
    }
    return sum;
};

double unsafe_sum(const double* values) {
    double sum = 0.0;
    while(*values) {
        sum += *values;
        values += sizeof(double);
    }
    return sum;
};

int main() {
    const double *local_doubles = (const double *)&my_doubles;

    printf("sizeof(double)=%zu\n", sizeof(double));

    printf("big sum=%f\n", safe_sum(other_doubles));

    double good_sum = safe_sum(local_doubles);
    printf("good sum: %f\n", good_sum);

    double bad_sum = unsafe_sum(local_doubles);
    printf("bad sum: %f\n", bad_sum);

    return 0;
}
