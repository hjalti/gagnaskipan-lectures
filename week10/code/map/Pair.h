#ifndef PAIR_H
#define PAIR_H

template<class T, class U>
struct Pair
{
	public:
		Pair(T first, U second);
		T first;
		U second;
};

template<class T, class U>
Pair<T,U>::Pair(T first, U second)
{
	this->first = first;
	this->second = second;
}

#endif
