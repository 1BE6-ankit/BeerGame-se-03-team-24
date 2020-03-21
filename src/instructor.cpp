#include "instructor.h"

Instructor::Instructor(QObject *parent) : QObject(parent){

}

Instructor::~Instructor(){

}


void Instructor::showGamesStatus(){

}

int Instructor::createGame(){
    return  1;
}

std::vector<int> Instructor::createGames(){
    std::vector<int> v;
    return  v;
}

void Instructor::setInstrEmail(std::string const n_instrEmail){
    instrEmail = n_instrEmail;
    return;
}

void Instructor::setInstrPassword(std::string const n_instrPassword){
    instrPassword = n_instrPassword;
    return;
}

void Instructor::setInstrId(int n_instrId){
    instrid = n_instrId;
    return;
}

std::string Instructor::getInstrEmail(){
    return instrEmail;
}

std::string Instructor::getInstrPassword(){
    return instrPassword;
}

int Instructor::getInstrId(){
    return instrid;
}
