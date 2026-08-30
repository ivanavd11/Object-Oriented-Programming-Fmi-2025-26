#pragma once
#include "Profile.h"
#include "Publisher.h"
#include <vector>
#include <memory>

template<typename T>
class Poster :public Profile, public Publisher
{
private:
	std::vector<std::unique_ptr<T>> posts;

	std::vector<Subscriber<T>*> subscribers;
public:
	explicit Poster(const std::string& username)
		: Profile(username) {}

	void createPost(T content)
	{
		posts.push_back(std::make_unique<T>(std::move(content)));

		std::cout << getUsername()
			<< " created a new post: "
			<< *posts.back() << '\n';

		notify();
	}

	void subscribe(Subscriber<T>* sub) override
	{
		if (sub == nullptr)
		{
			return;
		}

		for (const auto& it : subscribers)
		{
			if (it == sub)
			{
				return;
			}
		}
		subscribers.push_back(sub);
	}
	void unsubscribe(Subscriber<T>* sub) override
	{
		auto it = std::remove(subscribers.begin(), subscribers.end(), sub);
		subscribers.erase(it, subscribers.end);

	}
	void notify() override
	{
		if (posts.empty())
		{
			return;
		}
		
		const T& newestPost = *posts.back();

		for (Subscriber<T>* subscriber : subscribers) 
		{
			subscriber->update(newestPost);
		}
	}

	virtual ~Poster() = default;
};

#include "Subscriber.h"

template<typename T>
class Reader : public Profile, public Subscriber<T> {
private:
	std::vector<T> receivedPosts;

public:
	explicit Reader(const std::string& username)
		: Profile(username) {}

	void update(T data) override {
		receivedPosts.push_back(std::move(data));

		std::cout << getUsername()
			<< " received notification: "
			<< receivedPosts.back() << '\n';
	}

	std::size_t getReceivedPostsCount() const {
		return receivedPosts.size();
	}
	const T& getReceivedPost(std::size_t index) const {
		if (index >= receivedPosts.size()) {
			throw std::out_of_range(
				"Invalid received post index."
			);
		}

		return receivedPosts[index];
	}
};