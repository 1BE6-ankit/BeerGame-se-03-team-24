#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>
#include <QObject>

class Player: public QObject
{
    Q_OBJECT
public:
    /*
     * \brief Constructor for game class, sets the default values for game class
    */
    explicit Player(QObject *parent = nullptr);

    /*
     * \brief Constructor for game class, sets the default values for game class
     * \param n_role seeting value for player role in the game
    */
    Player(int n_role);

    /*
     * \brief distructor for game class
    */
    ~Player();


    /*
     * \brief Method to order a shipment from a player
     * \param numberOfBeers is number of beers to be ordered
     * \param From is the player from where the order is ordered
    */
    void order(int numberOfBeers, Player from);

    /*
     * \brief Method to ship a shipment to the player
     * \param numberOfBeers is number of beers to be shipped
     * \param to is the player from where the order is to be shipped
    */
    void ship(int numberOfBeers, Player to);

    /*
     * \brief Method to decrease inventory
     * \param numberOfBeers is number of beers to be decreased in the inventory
    */
    int decreaseInventory(int numberOfBeers);

    /*
     * \brief Method to increase inventory
     * \param numberOfBeers is number of beers to be increased in the inventory
    */
    int increaseInventory(int numberOfBeers);

    /*
     * \brief Method to receive Shipment
     * \param OrderID is id of order to be received
    */
    void receiveShipment(int orderID);



    /*
     * \brief Setter method for the Player Id
     * \param n_PId seeting value for player Id
    */
    void setPId(int n_PId);

    /*
     * \brief Setter method for the Player role
     * \param n_role seeting value for player role
    */
    void setRole(int n_role);

    /*
     * \brief Setter method for the Player Inventory
     * \param n_inventory seeting value for player inventory
    */
    void setInventory(int n_inventory);

    /*
     * \brief Setter method for the Player's backorder
     * \param n_backorder seeting value for player's backorder
    */
    void setBackorder(int n_backorder);

    /*
     * \brief Setter method for the Player's cost
     * \param n_cost seeting value for player's cost
    */
    void setCost(int n_cost);

    /*
     * \brief Setter method for the Players's demand
     * \param n_demand seeting value for player's demand
    */
    void setDemand(int n_demand);

    /*
     * \brief Setter method for the Player's order to be placed
     * \param n_order seeting value for player's order to be placed
    */
    void setOrderPlaced(int n_order);




    /*
     * \brief Getter method for Player Id
     * \return Instructor Id
    */
    int getPId();

    /*
     * \brief Getter method for Player's role in the game
     * \return role
    */
    int getRole();

    /*
     * \brief Getter method for player's inventory
     * \return player's inventory
    */
    int getInventory();

    /*
     * \brief Getter method for backorder cost
     * \return backorder cost
    */
    int getBackorder();

    /*
     * \brief Getter method for player's cost
     * \return cost
    */
    int getCost();

    /*
     * \brief Getter method for demand of player
     * \return player id
    */
    int getDemand();

    /*
     * \brief Getter method for order to be placed
     * \return order placed
    */
    int getOrderPlaced();


private:
    /*
    * \brief Attribute for Player Id
    */
    int pId;

    /*
    * \brief Attribute for role of player in game
    */
    int role;

    /*
    * \brief Attribute for current inventory of the player
    */
    int inventory;

    /*
    * \brief Attribute for current backorder of the player
    */
    double backorder;

    /*
    * \brief Attribute for current cost of player in the game
    */
    double cost;

    /*
    * \brief Attribute for current demand of player in game
    */
    int demand;

    /*
    * \brief Attribute for order placed by the player
    */
    int orderPlaced;





};

#endif // PLAYER_H
