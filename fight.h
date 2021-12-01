#pragma once

#include <iostream>

#include "fightstat.h"
/**
 * \brief Represents a fight
 * \details Class holding data pertaining to a fight instance
 * \author Paul Scoropan
 */
class Fight {
public: // public methods
    /**
     * \brief Fight constructor
     * \details Constructor sets all member variables
     * \param[in] fightID fight ID
     * \param[in] order fight order
     * \param[in] status fight status
     * \param[in] weightClass fight weight class
     * \param[in] cardSegment fight card segment
     * \param[in] referee fight referee
     * \param[in] rounds fight rounds
     * \param[in] resultClock fight result clock
     * \param[in] resultRound fight result round
     * \param[in] resultType fight result type
     * \param[in] winnerID fight winner ID
     * \param[in] active is fight active
     * \param[in] fightStats fight stats array
     */
    Fight(int fightID,
          int order,
          std::string status,
          std::string weightClass,
          std::string cardSegment,
          std::string referee,
          int rounds,
          int resultClock,
          int resultRound,
          std::string resultType,
          int winnerID,
          bool active,
          FightStat fightStats[2]);
    /**
     * \brief Fight destructor
     * \details Destructor deletes memory on heap
     * \author Paul Scoropan
     */
    ~Fight(); // deconstructor

    /**
     * \brief Get fight ID
     * \details Returns fight ID
     * \author Paul Scoropan
     * \return fight ID
     */
    int getFightID();

    /**
     * \brief Get fight order
     * \details Returns fight order
     * \author Paul Scoropan
     * \return fight order
     */ 
    int getOrder();

    /**
     * \brief Get fight status
     * \details Returns fight status
     * \author Paul Scoropan
     * \return fight status
     */
    std::string getStatus(); 

    /**
     * \brief Get fight weight class
     * \details Returns fight weight class
     * \author Paul Scoropan
     * \return fight weight class
     */
    std::string getWeightClass();

    /**
     * \brief Get fight card segment
     * \details Returns fight card segment
     * \author Paul Scoropan
     * \return fight card segment
     */
    std::string getCardSegment();

    /**
     * \brief Get fight referee
     * \details Returns fight referee
     * \author Paul Scoropan
     * \return fight referee
     */
    std::string getReferee();

    /**
     * \brief Get fight rounds
     * \details Returns fight rounds
     * \author Paul Scoropan
     * \return fight rounds
     */
    int getRounds();

    /**
     * \brief Get fight result clock
     * \details Returns fight result clock
     * \author Paul Scoropan
     * \return fight result clock
     */
    int getResultClock();

    /**
     * \brief Get fight result round
     * \details Returns fight result round
     * \author Paul Scoropan
     * \return fight result round
     */
    int getResultRound();

    /**
     * \brief Get fight result type
     * \details Returns fight result type
     * \author Paul Scoropan
     * \return fight result type
     */
    std::string getResultType();

    /**
     * \brief Get fight winner ID
     * \details Returns fight winner ID
     * \author Paul Scoropan
     * \return fight winner ID
     */
    int getWinnerID();

    /**
     * \brief Get is fight active
     * \details Returns is fight active
     * \author Paul Scoropan
     * \return is fight active
     */
    bool isActive();
    
    /**
     * \brief Get fight stats array
     * \details Returns fight stats array
     * \author Paul Scoropan
     * \return fight stats array
     */
    FightStat* getFightStats();
private: // private member variables
    int fightID; /*!< \brief fight ID*/

    int order; /*!< \brief fight ID*/

    std::string status;  /*!< \brief fight ID*/
    std::string weightClass; /*!< \brief fight weight class*/
    std::string cardSegment; /*!< \brief fight card segment*/
    std::string referee; /*!< \brief fight referee*/

    int rounds; /*!< \brief fight rounds*/
    int resultClock; /*!< \brief fight result clock*/
    int resultRound; /*!< \brief fight result round*/

    std::string resultType; /*!< \brief fight result type*/
    int winnerID; /*!< \brief fight winner ID*/
    bool active; /*!< \brief fight active*/

    FightStat fightStats[2]; /*!< \brief fight stats array*/
};