#include <stdio.h>
#include <math.h>

// Igor Krzywda
// Lista 1, zadanie 1

const long double kTargetPi = 3.141592653589793238462643383279L;

double double_pi(int k) {
    double pi = 0, delta;
    for (double i = 0; i < k; ++i) {
        delta = (1 / pow(16, i)) * (((4 / (8 * i + 1)) - (2 / (8 * i + 4))
                        - (1 / (8 * i + 5)) - (1 / (8 * i + 6))));
        pi += delta;
    }
    return pi;
}

long double long_double_pi(int k) {
    long double pi = 0, delta;
    for (long double i = 0; i < k; ++i) {
        delta = (1 / pow(16, i)) * (((4 / (8 * i + 1)) - (2 / (8 * i + 4))
                        - (1 / (8 * i + 5)) - (1 / (8 * i + 6))));
        pi += delta;
    }
    return pi;
}

int main() {
    double pi_1 = double_pi(100);
    long double pi_2 = long_double_pi(100);
    long double approx = acosl(-1);

    printf("Approximation:\n\n \
            \rDouble appr.: \t\t%.21f\n\
            \rLong double appr.: \t%.21Lf\n \
            \rWikipedia value: \t%.21Lf\n\
            \racosl(-1): \t\t%.21Lf\n",
            pi_1, pi_2, 
            kTargetPi, 
            approx);

    printf("\n\nError in relation to acosl(-1): \n\n \
            \rDouble appr.: \t\t%Lg\n\
            \rLong double appr.: \t%Lg\n \
            \rWikipedia value: \t%Lg\n",
            (approx - pi_1), (approx - pi_2), 
            (approx - kTargetPi)); 
    return 0;
}

