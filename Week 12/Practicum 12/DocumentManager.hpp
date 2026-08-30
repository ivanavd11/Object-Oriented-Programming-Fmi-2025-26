#pragma once

#include "User.hpp"

template<typename T>
class DocumentManager
{
private:
	std::vector<User< T >> users;

public:
	DocumentManager() = default;

	void addUser(const User< T >& user)
	{
		if (user)
		{
			users.push_back(user);
		}
		else
		{
			throw std::runtime_error("User is not found");
		}
	}

	User< T >& findUser(const std::string& name)
	{
		for (User<T>& user : users)
		{
			if (user.getName() == name)
			{
				return user;
			}
		}
		throw std::runtime_error("User not found.");
	}

	const User<T>& findUser(const std::string& name) const 
	{
		for (const User<T>& user : users) {
			if (user.getName() == name) {
				return user;
			}
		}
		throw std::runtime_error("User not found.");
	}

	std::size_t getUsersCount() const {
		return users.size();
	}
};
