#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000000

void initRndGen() {
    srand(time(NULL));
}
double getRandomNumber() {
    return ((double)rand() / RAND_MAX);
}

double pHgInv(double g, double ksi) {
    double tmp = (1 - pow(g, 2)) / (1 - g + 2 * g * ksi);
    return (1 + pow(g, 2) - pow(tmp, 2)) / (2 * g);
}

double calculateIntegral(double g) {
    int i, n = N;
    double integral = 0;

    for (i = 0; i < n; ++i) {
        double z1 = - log(getRandomNumber());
        double ro = -log(getRandomNumber());
        double t = pHgInv(g, getRandomNumber());
        if (z1 >= fmax(0, - ro * t))
            integral += exp( - z1 - ro * t);
    }

    return integral / n;
}
int main(void) {
    double g[9] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9 };
    int i;
    FILE *f;

    initRndGen();

    if ((f = fopen("../results.csv", "w")) != NULL) {
        printf("Calculating :\n");
        fprintf(f, "g, integral\n");
        for (i = 0; i < 9; ++i)
            fprintf(f, "%lf, %lf\n", g[i], calculateIntegral(g[i]));
    } else {
        printf("ERROR: cannot open file to save results");
    }
    printf("Done, results saved at 'results.csv'");

    return 0;
}
