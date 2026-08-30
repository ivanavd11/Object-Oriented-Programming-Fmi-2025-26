#include "NaturalFeature.h"
#include <iostream>
#include <memory>

std::string NaturalFeature::kindToString() const
{
	switch (this->kind)
	{
	case FeatureKind::Volcano: return "Volcano";
	case FeatureKind::Forest: return "Forest";
	case FeatureKind::Lake: return "Lake";
	case FeatureKind::Bog: return "Bog";
	case FeatureKind::Mountain: return "Mountain";
	case FeatureKind::Desert: return "Desert";
	}
	return "Unknown";
}
NaturalFeature::NaturalFeature(const std::string& name, int threat, const Coords& coords, const FeatureKind& kind)
	:Landmark(name, threat, coords), kind(kind)
{
	
}

const FeatureKind& NaturalFeature::getKind() const
{
	return kind;
}

std::string NaturalFeature::getType() const
{
	return "Natural Feature";
}
void NaturalFeature::print() const
{
	printBaseInfo();
	std::cout << ", feature kind: " << kindToString() << "\n";
}

std::unique_ptr<Landmark> NaturalFeature::clone() const
{
	return std::make_unique<NaturalFeature>(*this);
}
