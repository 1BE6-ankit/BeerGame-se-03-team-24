#include "player.h"

#ifndef _PLAYER_EVENT_H
#define _PLAYER_EVENT_H

class PlayerInterface;

class PlayerEvent {
protected:
    int eventId;
    int numberOfBeers;
    int orderedInWeek; // in which week is this event executed
    PlayerInterface* receiver;

    // for test cases
    int shippedInWeek;
    int toPlayerId;
    int fromPlayerId;
    int gId;


public:
    PlayerEvent(int eventId, int numberOfBeers, int orderedInWeek, PlayerInterface* receiver) :
        eventId(eventId),
        numberOfBeers(numberOfBeers),
        orderedInWeek(orderedInWeek),
        receiver(receiver)
    {};

    int getEventId() const {
        return eventId;
    };

    void setOrderedInWeek(int week) {
        this->orderedInWeek = week;
    };

    int getOrderedInWeek() const {
        return orderedInWeek;
    };

    void setNumberOfBeers(int numberOfBeers) {
        this->numberOfBeers = numberOfBeers;
    }

    int getNumberOfBeers() {
        return numberOfBeers;
    }

    // for the sake of test case
    void setFromPlayerId(int s) {
        this->fromPlayerId = s;
    }

    int getFromPlayerId() {
        return fromPlayerId;
    }

    void setToPlayerId(int s) {
        this->toPlayerId = s;
    }

    int getToPlayerId() {
        return toPlayerId;
    }

    void setShippedInWeek(int s) {
        this->shippedInWeek = s;
    }

    int getShippedInWeek() {
        return shippedInWeek;
    }

    void setGId(int g) {
        this->gId = g;
    }

    int getGId() {
        return gId;
    }

    void setOrderId(int id) {
        this->eventId = id;
    }

    int getOrderId() {
        return eventId;
    }
};

#endif
