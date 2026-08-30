#pragma once
#include "Component.h"

#include <memory>
#include <optional>
#include <iostream>

std::optional<std::unique_ptr<Component>>createComponent();

