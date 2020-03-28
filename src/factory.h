#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <vector>

/**
 * @brief what does this class do?
*/

class Factory
{
private:
    int productionTime;

public: // every function here has been made void just for making template, change it accordingly
    /**
    * @brief what does it do?
    */
    void produce(int numberOfBeers);

};

#endif //FACTORY_H