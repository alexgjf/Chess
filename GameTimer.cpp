#include "GameTimer.hpp"

GameTimer::GameTimer() {
    gameTime = seconds(0.0f);
    whiteTime = seconds(0.0f);
    blackTime = seconds(0.0f);
}

void GameTimer::resetTimer() {
    clock.restart();
}

String GameTimer::getWTimeString() {
    formatString();
    whiteTime = clock.getElapsedTime() - blackTime;

    minutesString << (int)whiteTime.asSeconds()/60;
    secondsString << (int)whiteTime.asSeconds()%60;

    return(minutesString.str() + ":" + secondsString.str());
}

String GameTimer::getBTimeString() {
    formatString();
    blackTime = clock.getElapsedTime() - whiteTime;

    minutesString << (int)blackTime.asSeconds()/60;
    secondsString << (int)blackTime.asSeconds()%60;

    return(minutesString.str() + ":" + secondsString.str());
}

void GameTimer::formatString() {
    minutesString.str("");
    minutesString << std::setfill('0') << std::setw(2);
    secondsString.str("");
    secondsString << std::setfill('0') << std::setw(2);
}