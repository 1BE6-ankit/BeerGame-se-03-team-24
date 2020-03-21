#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <QObject>
#include "order.h"

class Game: public QObject
{
    Q_OBJECT
public:
    /*
     * \brief Constructor for game class, sets the default values for game class
    */
     explicit Game(QObject *parent = nullptr);

    /*
     * \brief distructor for game class
    */
    ~Game();

    /*
     * \brief Method to execute orders for current week
    */
    int executeOrdersForCurrentWeek();

    /*
     * \brief Method to update player inventories
    */
    int updatePlayerInventories();

    /*
     * \brief Method advance a week during the game
    */
    int advanceWeek();

    /*
     * \brief Method to add order
     * \param order is the order to be added
    */
    void addOrder(Order order);

    /*
     * \brief Method to generate passwords for player in the game
     * \param n describes the no of passwords to be generated
    */
    std::vector<std::string> generatePasswords(int n);



    /*
     * \brief Setter method for the Game Id
     * \param n_id seeting value Game Id
    */
    void setGId(int n_id);

    /*
     * \brief Setter method for the Instructor Id
     * \param n_id seeting value for Instructor Id
    */
    void setInstrId(int n_id);

    /*
     * \brief Setter method for the Factory Id
     * \param n_id seeting value for Factory Id
    */
    void setPFactId(int n_id);

    /*
     * \brief Setter method for the Distributor Id
     * \param n_id seeting value for Distributor Id
    */
    void setPDistributorId(int n_id);

    /*
     * \brief Setter method for the Wholesaler Id
     * \param n_id seeting value for Wholesaler Id
    */
    void setPWholesalerId(int n_id);

    /*
     * \brief Setter method for the Retailer Id
     * \param n_id seeting value for Retailer Id
    */
    void setPRetailerId(int n_id);

    /*
     * \brief Setter method for the Order Time delay
     * \param n_id seeting value for Order Time delay
    */
    void setOrderTimeDelay(int n);

    /*
     * \brief Setter method for Weeks to be played
     * \param n seeting value for Weeks to be played
    */
    void setWeeksToBePlayed(int n);

    /*
     * \brief Setter method for the Info code
     * \param n seeting value for Info code
    */
    void setInfoCode(int n);

    /*
     * \brief Setter method for the Holding cost
     * \param n seeting value for Holding cost
    */
    void setHoldingCost(double n);

    /*
     * \brief Setter method for the Starting inventory
     * \param n seeting value for starting inventory
    */
    void setStartingInventory(int n);

    /*
     * \brief Setter method for Backorder cost
     * \param n seeting value for Backorder cost
    */
    void setBackorderCost(double n);

    /*
     * \brief Setter method for the Current Week
     * \param n seeting value for current week
    */
    void setCurrentWeek(int n);

    /*
     * \brief Setter method for the Order delay
     * \param n seeting value for the order delay
    */
    void setOrderDelay(int n);

    /*
     * \brief Setter method for the Shipment delay
     * \param n seeting value for shipment delay
    */
    void setShipmentDelay(int n);



    /*
     * \brief Getter method for Game Id
     * \return Game Id
    */
    int getGId();

    /*
     * \brief Getter method for instructor Id
     * \return Instructor Id
    */
    int getInstrId();

    /*
     * \brief Getter method for Factory Id
     * \return Factory Id
    */
    int getPFactId();

    /*
     * \brief Getter method for distributor Id
     * \return distributor Id
    */
    int getPDistributorId();

    /*
     * \brief Getter method for wholeseller Id
     * \return wholeseller Id
    */
    int getPWholesalerId();

    /*
     * \brief Getter method for retailer Id
     * \return retailer Id
    */
    int getPRetailerId();

    /*
     * \brief Getter method for Order Time dealy
     * \return order time delay
    */
    int getOrderTimeDelay();

    /*
     * \brief Getter method for weeks to be played
     * \return weeks to be played
    */
    int getWeeksToBePlayed();

    /*
     * \brief Getter method for Info Code
     * \return Info code
    */
    int getInfoCode();

    /*
     * \brief Getter method for Holding cost
     * \return Holding cost
    */
    double getHoldingCost();

    /*
     * \brief Getter method for Starting Inventory
     * \return Starting inventory
    */
    int getStartingInventory();

    /*
     * \brief Getter method for Backorder Cost
     * \return Backorder Cost
    */
    double getBackorderCost();

    /*
     * \brief Getter method for current cost
     * \return current cost
    */
    int getCurrentWeek();

    /*
     * \brief Getter method for Order delay
     * \return order Delay
    */
    int getOrderDelay();

    /*
     * \brief Getter method for Shipment delay
     * \return Shipment Delay
    */
    int getShipmentDelay();

    //std::vector<int> getOrdersToBeExecuted();


private:
    /*
    * \brief Attribute for Game Id
    */
    int gId;

    /*
    * \brief Attribute for Instructor Id
    */
    int InstrId;

    /*
    * \brief Attribute for Factory Id
    */
    int pFactId;

    /*
    * \brief Attribute for Distributor Id
    */
    int pDistributorId;

    /*
    * \brief Attribute for Wholeseller Id
    */
    int pWholesellerId;

    /*
    * \brief Attribute for Retailer Id
    */
    int pRetailerId;

    /*
    * \brief Attribute which maps orders to orders to be executed vector
    */
    std::map<int, std::vector<Order>> ordersToBeExecuted;

    /*
    * \brief Attribute which defines the order for that week
    */
    std::vector <int> demandPerWeek;

    /*
    * \brief Attribute for Order time delay
    */
    int orderTimeDelay;

    /*
    * \brief Attribute for Holding cost for a game
    */
    double holdingCost;

    /*
    * \brief Attribute for Back order cost for a game
    */
    double backorderCost;

    /*
    * \brief Attribute for Starting inventory
    */
    int StartingInventory;

    /*
    * \brief Attribute to define total no of weeks the game is being played
    */
    int weeksToBePlayed;

    /*
    * \brief Attribute for Current week
    */
    int currentWeek;

    /*
    * \brief Attribute for info code
    */
    int infoCode;

    /*
    * \brief Attribute for Order delay
    */
    int orderDelay;

    /*
    * \brief Shipment delay of a specific game
    */
    int shipmentDelay;





};

#endif // GAME_H
