#pragma once
#include "Subscriber.h"

template<typename T>
class Publisher
{
public:
	virtual void subscribe(Subscriber<T>* sub) = 0;
	virtual void unsubscribe(Subscriber<T>* sub) = 0;
	virtual void notify() = 0;
	virtual ~Publisher() = default;
};
