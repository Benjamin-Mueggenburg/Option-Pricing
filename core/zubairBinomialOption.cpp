#include <cmath>
#include <algorithm>
#include <iostream>

#include "zubairBinomialOption.h"

namespace Binomial {
     
    ZubairBinomialOption::~ZubairBinomialOption() {

    }

    double ZubairBinomialOption::getSpotPrice(int currentStep, int numberOfUpMovements) {
        return _initialPrice * std::pow(_up, 2*currentStep - (numberOfUpMovements - 1));
    }

    double ZubairBinomialOption::getExerciseValue(int currentStep, int numberOfUpMovements) {
        return std::max<double>(getSpotPrice(currentStep, numberOfUpMovements) - _strikePrice, 0.0);
    }

    double ZubairBinomialOption::getNodeValue_European(double currentValue, double futureValue) {
        return (ZubairBinomialOption::_pUp * futureValue + _pDown * currentValue) * std::exp(-_riskFreeRate * _deltaT);
    }

}