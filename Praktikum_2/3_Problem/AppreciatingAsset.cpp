#include <iostream>
#include "AppreciatingAsset.hpp"

double AppreciatingAsset :: getValue(int years){
    double temp = 1;
    for(int i = 0 ; i < years ; i++){
        temp *= (1 + rate);
    }
    return x->getValue(years)*temp;
}