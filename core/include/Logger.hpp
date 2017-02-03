#ifndef LOGGER_HPP
#define LOGGER_HPP

namespace soap {

class Logger {

public :
    static Logger& Log();

private :
    static Logger _log;

    Logger();
    ~Logger();

    void W();


};

}

#endif
