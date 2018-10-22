#ifndef SETTINGS_H
#define SETTINGS_H

#include "Pair.h"

template <typename T>
class Settings
{
public:
	Settings();
	Settings(Pair<T> * prs, int count);
	Settings(const Settings & currSettings);
	~Settings();
	Settings<T> & operator=(const Settings<T> & currSettings);
	int count() const; // Returns the number of pairs.

	void set(char * key, T value);// Sets a key to a given value in a pair.
	bool get(char * key, T & value) const; // Gets a value of a key.
private:
	Pair<T> * pairs; // Holds all pairs.
	int currCapacity; // The current capacity allocated.
	int pairCount; // The number of pairs.

	void grow(); // Grows the array if filled.
	void copyFrom(const Settings<T> & currSettings); // Copy function.
};

template <typename T>
Settings<T>::Settings()
{
	pairCount = 0;
	currCapacity = 10;
	pairs = new Pair<T>[currCapacity];
}

template <typename T> 
Settings<T>::Settings(Pair<T> * prs, int count)
{
	pairCount = count;
	currCapacity = count * 2;
	pairs = new Pair<T>[currCapacity];
	for (int i = 0; i < count; i++)
	{
		pairs[i] = prs[i];
	}
}

template< typename T>
Settings<T>::Settings(const Settings & currSettings)
{
	copyFrom(currSettings);
}

template< typename T>
Settings<T>::~Settings()
{
	delete[] pairs;
}

template <typename T>
Settings<T> & Settings<T>::operator=(const Settings<T> & currSettings)
{
	if (this != &currSettings)
	{
		delete[] pairs;
		copyFrom(currSettings);
	}
	return *this;
}


template <typename T>
int Settings<T>::count() const
{
	return pairCount;
}

template <typename T>
void Settings<T>::set(char * key, T value)
{
	for (int i = 0; i < pairCount; i++)
	{
		if (strcmp(pairs[i].getKey(), key) == 0)
		{
			pairs[i].setValue(value);
			return;
		}
	}
	if (pairCount >= currCapacity)
	{
		grow();
	}
	pairs[pairCount++] = Pair<T>(key, value);
}

template< typename T>
bool Settings<T>::get(char * key, T & value) const
{
	for (int i = 0; i < pairCount; i++)
	{
		if (strcmp(pairs[i].getKey(), key) == 0)
		{
			value = pairs[i].getValue();
			return true;
		}
	}
	return false;
}

template< typename T>
void Settings<T>::grow()
{
	Pair<T> * newPairs = new Pair<T>[currCapacity * 2];
	for (int i = 0; i < pairCount; i++)
	{
		newPairs[i] = pairs[i];
	}
	delete[] pairs;
	pairs = newPairs;
	currCapacity *= 2;
}

template <typename T>
void Settings<T>::copyFrom(const Settings & currSettings)
{
	pairCount = currSettings.pairCount;
	currCapacity = currSettings.currCapacity;
	pairs = new Pair<T>[currCapacity];
	for (int i = 0; i < pairCount; i++)
	{
		pairs[i] = currSettings.pairs[i];
	}
}

#endif