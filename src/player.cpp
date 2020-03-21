#include "player.h"

Player::Player(QObject *parent) : QObject(parent){

}

Player::Player(int n_role):role(n_role){
    pId = rand()%20;
    inventory = orderPlaced = demand = backorder = cost = 0;

}

Player::~Player(){

}

//functionality methods
void Player::order(int numberOfBeers, Player from){


}

void Player::ship(int numberOfBeers, Player to){

}

int Player::decreaseInventory(int numberOfBeers){
    inventory = inventory - numberOfBeers;
    return inventory;
}

int Player::increaseInventory(int numberOfBeers){
    inventory = inventory + numberOfBeers;
    return inventory;
}

void Player::receiveShipment(int orderID){

}

//setters

void Player::setPId(int n_PId){
    pId = n_PId;
    return;
}

void Player::setRole(int n_role){
    role = n_role;
    return;
}

void Player::setInventory(int n_inventory){
    inventory = n_inventory;
    return;
}

void Player::setBackorder(int n_backorder){
    backorder =  n_backorder;
    return;

}

void Player::setCost(int n_cost){
    cost = n_cost;
    return;
}

void Player::setDemand(int n_demand){
    demand = n_demand;
    return;

}

void Player::setOrderPlaced(int n_order){
    orderPlaced = n_order;
    return;
}

//getters

int Player::getPId(){
    return pId;
}

int Player::getRole(){
    return role;
}

int Player::getInventory(){
    return inventory;
}

int Player::getBackorder(){
    return backorder;
}

int Player::getCost(){
    return cost;
}

int Player::getDemand(){
    return demand;
}

int Player::getOrderPlaced(){
    return orderPlaced;
}

