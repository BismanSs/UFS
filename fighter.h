#pragma once

#include <iostream>

/**
 * \brief Represents a UFC fighter
 * \details Class to represent an instance of a UFC fighter with all relevant data
 * \author Paul Scoropan
 */
class Fighter {
public: // public methods
    /**
     * \brief Fighter constructor
     * \details Constructor sets all member variables
     * \author Paul Scoropan
     * \param[in] fighterID int
     * \param[in] firstName string
     * \param[in] lastName string
     * \param[in] nickname string
     * \param[in] weightClass string
     * \param[in] birthDate string
     * \param[in] height float
     * \param[in] weight float
     * \param[in] reach float
     * \param[in] wins int
     * \param[in] losses int
     * \param[in] draws int
     * \param[in] noContests int
     * \param[in] technicalKnockouts int
     * \param[in] technicalKnockoutLosses int
     * \param[in] submissions int
     * \param[in] submissionLosses int
     * \param[in] titleWins int
     * \param[in] titleLosses int
     * \param[in] titleDraws int
     * \param[in] sigStrikesLandedPerMinute float
     * \param[in] sigStrikeAccuracy float
     * \param[in] takedownAverage float
     * \param[in] submissionAverage float
     * \param[in] knockoutPercentage float
     * \param[in] technicalKnockoutPercentage float
     * \param[in] decisionPercentage float
     */
    Fighter(int fighterID,
            std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string weightClass,
            std::string birthDate,
            float height,
            float weight,
            float reach,
            int wins,
            int losses,
            int draws,
            int noContests,
            int technicalKnockouts,
            int technicalKnockoutLosses,
            int submissions,
            int submissionLosses,
            int titleWins,
            int titleLosses,
            int titleDraws,
            float sigStrikesLandedPerMinute,
            float sigStrikeAccuracy,
            float takedownAverage,
            float submissionAverage,
            float knockoutPercentage,
            float technicalKnockoutPercentage,
            float decisionPercentage);
    /**
     * \brief Deconstructor for Fighter
     * \details Deletes any memory allocated on the heap
     * \author Paul Scoropan
     */
    ~Fighter(); // deconstructor

    /**
     * \brief Get fighter ID
     * \details Returns fighter ID
     * \author Paul Scoropan
     * \return fighter ID
     */
    int getFighterID();

    /**
     * \brief Get fighter first name
     * \details Returns fighter first name
     * \author Paul Scoropan
     * \return fighter first name
     */
    std::string getFirstName();

    /**
     * \brief Get fighter last name
     * \details Returns fighter last name
     * \author Paul Scoropan
     * \return fighter last name
     */
    std::string getLastName();

    /**
     * \brief Get fighter nickname
     * \details Returns fighter nickname
     * \author Paul Scoropan
     * \return fighter nickname
     */
    std::string getNickname();

    /**
     * \brief Get fighter weight class
     * \details Returns fighter weight class
     * \author Paul Scoropan
     * \return fighter weight class
     */
    std::string getWeightClass();

    /**
     * \brief Get fighter birth date
     * \details Returns fighter birth date
     * \author Paul Scoropan
     * \return fighter birthdate
     */
    std::string getBirthDate();

    /**
     * \brief Get fighter height
     * \details Returns fighter height
     * \author Paul Scoropan
     * \return fighter height
     */
    float getHeight();

    /**
     * \brief Get fighter weight
     * \details Returns fighter weight
     * \author Paul Scoropan
     * \return fighter weight
     */
    float getWeight();

    /**
     * \brief Get fighter reach
     * \details Returns fighter reach
     * \author Paul Scoropan
     * \return fighter reach
     */
    float getReach();

    /**
     * \brief Get fighter wins
     * \details Returns fighter wins
     * \author Paul Scoropan
     * \return fighter wins
     */
    int getWins();

    /**
     * \brief Get fighter losses
     * \details Returns fighter losses
     * \author Paul Scoropan
     * \return fighter losses
     */
    int getLosses();

    /**
     * \brief Get fighter draws
     * \details Returns fighter draws
     * \author Paul Scoropan
     * \return fighter draws
     */
    int getDraws();

    /**
     * \brief Get fighter no contests
     * \details Returns fighter no contests
     * \author Paul Scoropan
     * \return fighter no contests
     */
    int getNoContests();

    /**
     * \brief Get fighter technical knockouts
     * \details Returns fighter technical knockouts
     * \author Paul Scoropan
     * \return fighter technical knockouts
     */
    int getTechnicalKnockouts();

    /**
     * \brief Get fighter technical knockout losses
     * \details Returns fighter technical knockout losses
     * \author Paul Scoropan
     * \return fighter technical knockout losses
     */
    int getTechnicalKnockoutLosses();

    /**
     * \brief Get fighter submissions
     * \details Returns fighter submissions
     * \author Paul Scoropan
     * \return fighter submissions
     */
    int getSubmissions();

    /**
     * \brief Get fighter submission losses
     * \details Returns fighter submission losses
     * \author Paul Scoropan
     * \return fighter submission losses
     */
    int getSubmissionLosses();

    /**
     * \brief Get fighter title wins
     * \details Returns fighter title wins
     * \author Paul Scoropan
     * \return fighter title wins
     */
    int getTitleWins();

    /**
     * \brief Get fighter title losses
     * \details Returns fighter title losses
     * \author Paul Scoropan
     * \return fighter title losses
     */
    int getTitleLosses();

    /**
     * \brief Get fighter title draws
     * \details Returns fighter title draws
     * \author Paul Scoropan
     * \return fighter title draws
     */
    int getTitleDraws();
    
    /**
     * \brief Get fighter significant strikes landed per minute
     * \details Returns fighter significant strikes landed per minute
     * \author Paul Scoropan
     * \return fighter significant strikes landed per minute
     */
    float getSigStrikesLandedPerMinute();

    /**
     * \brief Get fighter significant strike accuracy
     * \details Returns fighter significant strike accuracy
     * \author Paul Scoropan
     * \return fighter significant strike accuracy
     */
    float getSigStrikeAccuracy();

    /**
     * \brief Get fighter takedown average
     * \details Returns fighter takedown average
     * \author Paul Scoropan
     * \return fighter takedown average
     */
    float getTakedownAverage();

    /**
     * \brief Get fighter submission average
     * \details Returns fighter submission average
     * \author Paul Scoropan
     * \return fighter submission average
     */
    float getSubmissionAverage();

    /**
     * \brief Get fighter knockout percentage
     * \details Returns fighter knockout percentage
     * \author Paul Scoropan
     * \return fighter knockout percentage
     */
    float getKnockoutPercentage();

    /**
     * \brief Get fighter technical knockout percentage
     * \details Returns fighter technical knockout percentage
     * \author Paul Scoropan
     * \return fighter technical knockout percentage
     */
    float getTechnicalKnockoutPercentage();

    /**
     * \brief Get fighter decision percentage
     * \details Returns fighter decision percentage
     * \author Paul Scoropan
     * \return fighter decision percentage
     */
    float getDecisionPercentage();

private: // private member variables
    int fighterID; /*!< \brief fighter ID*/

    std::string firstName; /*!< \brief fighter first name*/
    std::string lastName; /*!< \brief fighter last name*/
    std::string nickname; /*!< \brief fighter nickname*/
    std::string weightClass; /*!< \brief fighter weight class*/
    std::string birthDate; /*!< \brief fighter birthdate*/

    float height; /*!< \brief fighter height*/
    float weight; /*!< \brief fighter weight*/
    float reach; /*!< \brief fighter reach*/

    int wins; /*!< \brief fighter wins*/
    int losses; /*!< \brief fighter losses*/
    int draws; /*!< \brief fighter draws*/
    int noContests; /*!< \brief fighter no contests*/
    int technicalKnockouts; /*!< \brief fighter technical knockouts*/
    int technicalKnockoutLosses; /*!< \brief fighter technical knockout losses*/
    int submissions; /*!< \brief fighter submissions*/
    int submissionLosses; /*!< \brief fighter submission losses*/
    int titleWins; /*!< \brief fighter title wins*/
    int titleLosses; /*!< \brief fighter title losses*/
    int titleDraws; /*!< \brief fighter title draws*/

    float sigStrikesLandedPerMinute; /*!< \brief fighter significant strikes landed per minute*/
    float sigStrikeAccuracy; /*!< \brief fighter significant strike accuracy*/
    float takedownAverage; /*!< \brief fighter takedown average*/
    float submissionAverage; /*!< \brief fighter submission average*/
    float knockoutPercentage; /*!< \brief fighter knockout percentage*/
    float technicalKnockoutPercentage; /*!< \brief fighter technical knockout percentage*/
    float decisionPercentage; /*!< \brief fighter decision percentage*/
};