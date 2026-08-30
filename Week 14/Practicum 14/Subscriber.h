#pragma once

template<typename T>
class Subscriber
{
public:
	virtual void update(T data) = 0;

	virtual ~Subscriber() = default;
};
