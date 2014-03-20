#ifndef MAP_H
#define MAP_H

#include "Pair.h"

class KeyException { };

class NoMoreElementsException { };

template<class K, class V>
class Map {

    public:
		virtual ~Map() { }

        virtual int size() const = 0;

        virtual bool empty() const = 0;

        virtual void add(K key, V value) = 0;

        virtual bool contains(K key) const = 0;

        virtual V& get(K key) const = 0;

        virtual void remove(K key) = 0;

		virtual V& operator[] (const K& key) = 0;

		class Iterator
		{
			public:
				virtual ~Iterator() { }
				virtual Pair<K,V> next() = 0;
				virtual bool has_next() = 0;
		};

		virtual Iterator* get_iterator() = 0;
};

#endif
