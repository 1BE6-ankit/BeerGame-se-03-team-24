#include "factory.h"

Factory::Factory(QObject *parent) : Player(parent){

}
Factory::~Factory(){

}


void Factory::setProductionTime(int value){
    productionTime = value;
    return;
}

int Factory::getProductionTime() const{
    return productionTime;
}

void Factory::produce(int n){
    return;
}



