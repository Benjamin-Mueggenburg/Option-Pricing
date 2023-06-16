#ifndef ZUBAIRBINOMIALOPTION_H
#define ZUBAIRBINOMIALOPTION_H

#include <cmath>
#include <iostream>

namespace Binomial {
    class ZubairBinomialOption {
        private:
            int _steps;
            double _deltaT;
            double _initialPrice;
            double _strikePrice;
            double _riskFreeRate;
            double _up;
            double _volatility;

            double _pUp;
            double _pDown;

        public:
        ZubairBinomialOption(int steps, double deltaT, double initialPrice, double strikePrice, double riskFreeRate, double volatility, double dividendYield = 0) {
            _steps = steps;
            _deltaT = deltaT;
            _initialPrice = initialPrice;
            _strikePrice = strikePrice;
            _riskFreeRate = riskFreeRate;
            _volatility = volatility;
            
            _up = std::exp(volatility * std::sqrt(deltaT));

            double down = 1.0/_up;
            _pUp = (std::exp((riskFreeRate - dividendYield) * deltaT) - down)/(_up - down);

            _pDown = 1-_pUp;
        };

        ~ZubairBinomialOption();

        double getSpotPrice(int currentStep, int numberOfUpMovements);

        double getExerciseValue(int currentStep, int numberOfUpMovements);

        double getNodeValue_European(double currentValue, double futureValue);
    };
};

#endif