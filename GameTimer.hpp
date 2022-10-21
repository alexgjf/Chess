#ifndef GAMETIMER_HPP
#define GAMETIMER_HPP

#include <SFML/Graphics.hpp>
//#include <time.h>
#include <sstream>

using namespace sf;


class GameTimer {
    private:
        Clock clock;
        Time gameTime;
        Time whiteTime;
        Time blackTime;
        std::stringstream secondsString;    //stringstreamobjects to format seconds and minutes properly
        std::stringstream minutesString;

        void formatString();
    
    public:
        GameTimer();
        String getWTimeString();
        String getBTimeString();
        void resetTimer();
};
#endif