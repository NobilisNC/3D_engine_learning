#ifndef INTERFACE_HPP
#define INTERFACE_HPP

template<typename T>
class Cloneable {
public :
    virtual T* clone() = 0;
};



#endif
