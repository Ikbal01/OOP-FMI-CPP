#ifndef PAIR_H/
#define PAIR_H

#include<string.h>

template <typename T>
class Pair
{
public:
	Pair();
	Pair(char * key, T value);
	Pair(const Pair<T> & currPair);
	~Pair();
	Pair<T> & operator=(const Pair<T> & currPair);

	const char * getKey() const; // Gets the key of the pair.
	T getValue() const; // Gets the value of the pair.
	void setValue(T val); // Sets the value of the pair.

private:
	char * key; // Key of the pair.
	T value; // Value of the pair.

	void copyFrom(const Pair & currPair);
};

template <typename T>
Pair<T>::Pair()
{
	const int keySize = 8;
	key = new char[keySize];
	strcpy_s(key, keySize, "default");
}

template <typename T>
Pair<T>::Pair(char * key, T value)
{
	int length = strlen(key);
	this->key = new char[length + 1];
	strcpy_s(this->key, length + 1, key);
	this->value = value;
}

template <typename T>
Pair<T>::Pair(const Pair<T> & currPair)
{
	copyFrom(currPair);
}

template <typename T>
Pair<T>::~Pair()
{
	delete[] key;
}

template <typename T>
Pair<T> & Pair<T>::operator=(const Pair<T> & currPair)
{
	if (this != &currPair)
	{
		delete[] key;
		copyFrom(currPair);
	}
	return *this;
}

template <typename T>
const char * Pair<T>::getKey() const
{
	return key;
}

template <typename T>
T Pair<T>::getValue() const
{
	return value;
}

template <typename T>
void Pair<T>::setValue(T val)
{
	this->value = val;
}

template <typename T>
void Pair<T>::copyFrom(const Pair & currPair)
{
	int length = strlen(currPair.getKey());
	key = new char[length + 1];
	strcpy_s(this->key, length + 1, currPair.getKey());
	value = currPair.getValue();
}

#endif