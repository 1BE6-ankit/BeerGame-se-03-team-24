#ifndef ORDER_H
#define ORDER_H

#include "playerevent.h"
#include "player.h"

class Player;

/**
 * @brief what does this class do?
*/


class Order : public PlayerEvent {
public:
    Order();

    Order(int, int, int, PlayerInterface*);

    void executeEvent();
};


#endif //ORDER_H
