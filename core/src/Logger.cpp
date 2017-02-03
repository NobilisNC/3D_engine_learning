#include "Logger.hpp"

using namespace soap;

Logger Logger::_log = Logger();

Logger& Logger::Log()
{
    return _log;
}

Logger::Logger()
{

}

Logger::~Logger()
{

}
