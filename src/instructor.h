#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <QObject>

class Instructor: public QObject
{
    Q_OBJECT
public:

    /*
    * \brief Default constructor for instructor, creates a default Instuctor object
    */
    explicit Instructor(QObject *parent = nullptr);
    /*
    * \brief distructor for instructor
    */
    ~Instructor();

    /*
     * \brief Setter method for the instructor Id
     * \param n_instrId seeting value of instructor Id
    */
    void setInstrId(int n_instrId);


    /*
     * \brief Setter method for the instructor Email
     * \param n_instrEmail seeting value of instructor Email
    */
    void setInstrEmail(std::string const instrEmail);


    /*
     * \brief Setter method for the instructor Password
     * \param n_instrId seeting value of instructor Password
    */
    void setInstrPassword(std::string const n_instrPassword);

    /*
     * \brief Getter method for instructor Id
     * \return Instructor Id
    */
    int getInstrId();

    /*
     * \brief Getter method for instructor Email
     * \return Instructor Email
    */
    std::string getInstrEmail();

    /*
     * \brief Getter method for instructor Password
     * \return Instructor Password
    */
    std::string getInstrPassword();


private:
    /*
    * \brief Attribute for Instructor Id
    */
    int instrid;

    /*
    * \brief Attribute for Instructor Email
    */
    std::string instrEmail;

    /*
    * \brief Attribute for Instructor Password
    */
    std::string instrPassword;

    /*
     * \brief Displays status of game at that point of time
    */
    void showGamesStatus();

    /*
     * \brief creates a new game for the instructor object
    */
    int createGame();

    /*
     * \brief creates a new series of games for the instructor object
    */
    std::vector<int> createGames();



};

#endif // INSTRUCTOR_H
