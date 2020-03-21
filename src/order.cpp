#include "order.h"

Order::Order(QObject *parent) : QObject(parent){

}

//functionality methods

Order::Order(int n_orderId, int n_gID, int n_fromPlayer,
        int n_toPlayer, int n_orderedInWeek, int n_shippedInweek, int n_numberofBeers){
    orderid = n_orderId;
    gid = n_gID;
    fromPlayerid = n_fromPlayer;
    toPlayerid = n_toPlayer;
    orderedInWeek = n_orderedInWeek;
    shippedInWeek = n_shippedInweek;
    numberOfBeers = n_numberofBeers;
}

Order::~Order(){

}

void Order::executeOrder(){

}


//setters

void Order::setOrderId(int n){
    orderid = n;
    return;
}

void Order::setGId(int n){
    gid = n;
    return;
}

void Order::setFromPlayerId(int n){
    fromPlayerid = n;
    return;
}

void Order::setToPlayerId(int n){
    toPlayerid = n;
    return;
}

void Order::setOrderedInWeek(int n){
    orderedInWeek = n;
    return;
}

void Order::setShippedInWeek(int n){
    shippedInWeek = n;
    return;
}

void Order::setNumberOfBeers(int n){
    numberOfBeers = n;
    return;
}

//getters

int Order::getOrderId(){
    return orderid;
}

int Order::getGId(){
    return gid;
}

int Order::getFromPlayerId(){
    return fromPlayerid;
}

int Order::getToPlayerId(){
    return toPlayerid;
}

int Order::getOrderedInWeek(){
    return orderedInWeek;
}

int Order::getShippedInWeek(){
    return shippedInWeek;
}

int Order::getNumberOfBeers(){
    return numberOfBeers;
}
