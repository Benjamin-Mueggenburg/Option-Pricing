#ifndef BINOMIAL_H
#define BINOMIAL_H

#include <vector>

namespace Binomial {
    double vanillaBinomialAlgorithm(int steps, int expirationTime, double initialPrice, double strikePrice, double riskFreeRate, double volatility, double dividendYield = 0);
}
#endif