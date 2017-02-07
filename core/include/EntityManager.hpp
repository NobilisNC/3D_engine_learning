#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <map>
#include <functional>
#include <string>

namespace soap {

template<typename T, typename K>
class Manager {
public:
     struct Key {
        size_t hash;
    };

private :
    std::hash<T>        _hash_func;
    std::map<size_t, K*> _map;

    Key hash(T& t) {
        return Key{_hash_func(t)};
    }

    bool isLoaded(Key key) {
        return (_map.find(key.hash) != _map.end() ? true : false);
    }

public :
    Manager() {

    }

    ~Manager() {

    }

    template<typename... Args>
    Key insert(T t, Args&&... args) {
        Key key = hash(t);

        if(!isLoaded(key)){
            K* k= new K(t, args...);
            _map[key.hash] = k;
        }

        return key;

    }

    K& get(Key key) {
        return *_map[key.hash];
    }

    K& operator[](Key key) {
        return *_map[key.hash];
    }

};
}
#endif
