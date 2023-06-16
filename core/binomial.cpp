#include <math.h>
#include <algorithm>
#include <vector>

#include <iostream>

#include "zubairBinomialOption.h"

namespace Binomial
{

    double vanillaBinomialAlgorithm(int steps, int expirationTime, double initialPrice, double strikePrice, double riskFreeRate, double volatility, double dividendYield = 0) {
        
        double deltaT = (double)expirationTime / (steps * 365);
        ZubairBinomialOption *opt = new ZubairBinomialOption(steps, deltaT, initialPrice, strikePrice, riskFreeRate, volatility, dividendYield);

        std::vector<double> p;
        
        for (int i = 0; i < steps; i++) {
            p.push_back(std::max<double>(0, opt->getExerciseValue(i, steps+1)));
        }


        for (int j = steps; j > 0; j--) {
            for (int i = 0; i < steps; i++) {
                p[i] = opt->getNodeValue_European(p[i], p[i+1]);
            }

        }

        return p[0];
    }



} // namespace Binomial
