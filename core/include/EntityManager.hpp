#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <map>
#include <functional>
#include <string>

#include "Meta.hpp"
#include "Interface.hpp"

namespace soap {

template<typename T, typename K>
class EntityManager {
public:
    /**
      * @brief The Key struct : it used to Handle an entity.
      *
      */
     struct Key {
        size_t hash;
        EntityManager* manager;

        K* operator->() {
            return manager->_map[hash];
        }
    };


     /** *** *** *** **/

     /**
      * @brief The ChainedArg struct : it used to chained Manager(KEY).insert(args...);
      *
      */
     class ChainedArg {
     private :
         Key _k;
         EntityManager* _manager;
    public :
         ChainedArg(Key key, EntityManager* manager) : _k(key), _manager(manager) {}

         /*template<typename... Args>
         Key insert(Args... args) {
             return _manager->insert(_k, args...);
         }

         template<typename... Args>
         Key operator()(Args... args) {
             return _manager->insert(_k, args...);
         }*/

         Key operator()(Cloneable<K>&& c) {
             return _manager->insert(_k, c);
         }

         Key insert(Cloneable<K>&& c) {
             return _manager->insert(_k, c);
         }
     };

     /** *** *** *** **/

private :
    std::hash<T>        _hash_func;
    std::map<size_t, K*> _map;

    Key hash(T& t) {
        return Key{_hash_func(t), this};
    }

    bool isLoaded(Key key) {
        return (_map.find(key.hash) != _map.end() ? true : false);
    }


   /* template<typename... Args>
    Key insert(Key key, Args&&... args) {


        if(!isLoaded(key)){
            K* k= new K(args...);
            _map[key.hash] = k;
        }

        return key;
    }*/

    Key insert(Key key, Cloneable<K>& c) {

        if(!isLoaded(key)){
             K* k = c.clone();
            _map[key.hash] = k;
        }

        return key;
    }

public :
    EntityManager() {

    }

    ~EntityManager() {

    }

    ChainedArg operator()(T t) {
        Key key = hash(t);

        return ChainedArg(key, this);
    }




    K& get(Key key) {
        return *_map[key.hash];
    }

    K& operator[](Key key) {
        return *_map[key.hash];
    }

    friend class Key;
    friend class ChainedArg;
};
}
#endif
