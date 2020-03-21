#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <string>
#include <vector>
#include <cmath>
#include <QObject>
#include <iostream>

class Order: public QObject
{
    Q_OBJECT
public:
    /**
     * \brief Default constructor for order
    */
     explicit Order(QObject *parent = nullptr);
    /**
     * \brief Constructor for Order
     * \param n_orderId seeting value for orderId
     * \param n_gId seeting value for gId
     * \param n_fromId seeting value for fromId
     * \param n_toPlayer seeting value for oPlayer
     * \param n_orderInweek seeting value for orderInweek
     * \param n_shippedInweek seeting value for shippedInweek
     * \param n_numberofBeers seeting value for numberofBeers
    */
    Order(int n_orderId, int n_gID, int n_fromPlayer,
        int n_toPlayer, int n_orderedInWeek, int n_shippedInweek, int n_numberofBeers);

    /**
     * \brief distructor for order
    */
    ~Order();

    /**
     * \brief Method to execute order
    */
    void executeOrder();

    /**
     * \brief Setter method for the Order Id
     * \param n seeting value for Order Id
    */
    void setOrderId(int n);

    /**
     * \brief Setter method for the Game Id
     * \param n seeting value for Game Id
    */
    void setGId(int n);

    /**
     * \brief Setter method for the Player Id of source player of the order
     * \param n seeting value for player Id
    */
    void setFromPlayerId(int n);

    /**
     * \brief Setter method for the Player Id of destination player of the order
     * \param n seeting value for player Id
    */
    void setToPlayerId(int n);

    /**
     * \brief Setter method for the number of orders in a week
     * \param n seeting value for OrderedInWeek
    */
    void setOrderedInWeek(int n);

    /**
     * \brief Setter method for no of beers shipped in a week
     * \param n seeting value for Shipped in week
    */
    void setShippedInWeek(int n);

    /**
     * \brief Setter method for the number of beers in the order
     * \param n seeting value for Number of beers
    */
    void setNumberOfBeers(int n);




    /**
     * \brief Getter method for Order ID
     * \return Order ID
    */
    int getOrderId();

    /**
     * \brief Getter method for Game ID
     * \return GameID
    */
    int getGId();

    /**
     * \brief Getter method for player source ID for the order
     * \return source player ID
    */
    int getFromPlayerId();

    /**
     * \brief Getter method for destinatiion player ID of the order
     * \return destination player ID
    */
    int getToPlayerId();

    /**
     * \brief Getter method for week in which order was ordered
     * \return week no of orderd week
    */
    int getOrderedInWeek();

    /**
     * \brief Getter method for number of beers shipped in a week
     * \return beers shipped in the week
    */
    int getShippedInWeek();

    /**
     * \brief Getter method for number of beers in that order
     * \return number of beers in that order
    */
    int getNumberOfBeers();

signals:

private:
    /**
    * \brief Attribute for Order ID
    */
    int orderid;

    /**
    * \brief Attribute for Game Id
    */
    int gid;

    /**
    * \brief Attribute for describing the source player of order
    */
    int fromPlayerid;

    /**
    * \brief Attribute for describing the destination player of order
    */
    int toPlayerid;

    /**
    * \brief Attribute for orderes for a week
    */
    int orderedInWeek;

    /**
    * \brief Attribute for orders shipped in a week
    */
    int shippedInWeek;

    /**
    * \brief Attribute for describing number of beers for the order
    */
    int numberOfBeers;





};

#endif // ORDER_H
