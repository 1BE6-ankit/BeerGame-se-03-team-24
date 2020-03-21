#ifndef FACTORY_H
#define FACTORY_H


#include "player.h"


class Factory : public Player
{
public:
    /*
     * \brief Constructor for game class, sets the default values for game class
    */
    explicit Factory(QObject *parent = nullptr);

    /*
     * \brief distructor for game class
    */
    ~Factory();

    /*
     * \brief Setter method for production delay
     * \param n seeting value for the order delay
    */
    void setProductionTime(int value);

    /*
     * \brief Getter method for Production time
     * \return production time
    */
    int getProductionTime() const;
    /*
    * \brief Attribute for describing number of beers to be produced
    */
    void produce(int n);


private:
    /*
    * \brief Attribute for Production Time
    */
    int productionTime;

};

#endif // FACTORY_H
