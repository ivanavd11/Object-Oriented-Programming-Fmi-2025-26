#pragma once
#include "Landmark.h"

enum class FeatureKind
{
    Volcano, Forest, Lake, Bog, Mountain, Desert
};

class NaturalFeature :public Landmark
{
    FeatureKind kind;

	std::string kindToString() const;
public:
	NaturalFeature(const std::string& name, int threat, const Coords& coords, const FeatureKind& kind);

	const FeatureKind& getKind() const;

	std::string getType() const override;
	void print() const override;

	std::unique_ptr<Landmark> clone() const override;
};

