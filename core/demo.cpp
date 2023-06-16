#include <iostream>
#include "binomial.h"


int main() {
    std::cout << "Running on the following parameters" << std::endl;
    
    double PrevOptionValue = Binomial::vanillaBinomialAlgorithm(100, 1, 127.62, 130, 0.001, 0.2);

    for (int daysToExpiration = 2; daysToExpiration <= 252; daysToExpiration++) {
        double p = Binomial::vanillaBinomialAlgorithm(100, daysToExpiration, 127.62, 130, 0.001, 0.2);

        double theta = (p - PrevOptionValue) / (1);
        PrevOptionValue = p;
        
        std::cout << daysToExpiration << "," << theta << std::endl;
    }

    

}