#include "game.h"

Game::Game(QObject *parent) : QObject(parent){
    InstrId = rand()%20;
    gId = InstrId + 1;
    pFactId = gId + 1;
    pDistributorId = gId + 2;
    pWholesellerId = gId + 3;
    pRetailerId = gId + 4;
    //ordersToBeExecuted.assign(4,5);
    demandPerWeek.assign(5,5);
    orderTimeDelay = 2;
    holdingCost = 0.5;
    backorderCost = 1;
    StartingInventory = 12;
    weeksToBePlayed = 26;
    currentWeek = 0;
    infoCode = 0;
    orderDelay = 2;
    shipmentDelay = 2;
}

Game::~Game(){

}

//functionality methods
int Game::executeOrdersForCurrentWeek(){
    return 0;

}

int Game::updatePlayerInventories(){
    return 0;
}


int Game::advanceWeek(){
    currentWeek = currentWeek + 1;
    return currentWeek;

}

void Game::addOrder(Order order){

}

std::vector<std::string> Game::generatePasswords(int n){
    const char *seq = "abcdefghijklmnopqrstuvwxyz123456789!*ABCDEFGHIJKLMNOP)($";
    std::string pass;

    std::vector<std::string> password;
    for (int j = 0; j < n; ++j){
        for (int i = 0; i < 5; ++i)
            pass[i]= seq[rand()%45];
        password.push_back(pass);
    }
    return password;
}

//setters

void Game::setGId(int n_id){
    gId = n_id;
    return;
}

void Game::setInstrId(int n_id){
    InstrId = n_id;
    return;
}

void Game::setPFactId(int n_id){
    pFactId = n_id;
    return;
}

void Game::setPDistributorId(int n_id){
    pDistributorId = n_id;
    return;
}

void Game::setPWholesalerId(int n_id){
    pWholesellerId = n_id;
    return;
}

void Game::setPRetailerId(int n_id){
    pRetailerId = n_id;
    return;
}

void Game::setOrderTimeDelay(int n){
    orderTimeDelay = n;
    return;
}

void Game::setWeeksToBePlayed(int w){
    weeksToBePlayed = w;
    return;
}

void Game::setInfoCode(int n){
    infoCode = n;
    return;
}

void Game::setHoldingCost(double n){
    holdingCost = n;
    return;
}

void Game::setStartingInventory(int n){
    StartingInventory = n;
    return;
}

void Game::setBackorderCost(double n){
    backorderCost = n;
    return;
}

void Game::setCurrentWeek(int w){
    currentWeek = w;
    return;
}

void Game::setOrderDelay(int n){
    orderDelay = n;
    return;
}


void Game::setShipmentDelay(int n){
    shipmentDelay = n;
    return;
}


//getters

int Game::getGId(){
    return gId;
}

int Game::getInstrId(){
    return InstrId;
}

int Game::getPFactId(){
    return pFactId;
}

int Game::getPDistributorId(){
    return pDistributorId;
}

int Game::getPWholesalerId(){
    return pWholesellerId;
}

int Game::getPRetailerId(){
    return pRetailerId;
}

int Game::getOrderTimeDelay(){
    return orderTimeDelay;
}

int Game::getWeeksToBePlayed(){
    return weeksToBePlayed;
}

int Game::getInfoCode(){
    return infoCode;
}

double Game::getHoldingCost(){
    return holdingCost;
}

int Game::getStartingInventory(){
    return StartingInventory;
}

double Game::getBackorderCost(){
    return backorderCost;
}

int Game::getCurrentWeek(){
    return currentWeek;
}

int Game::getOrderDelay(){
    return orderDelay;
}

int Game::getShipmentDelay(){
    return shipmentDelay;
}




