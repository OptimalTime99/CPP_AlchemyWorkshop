// PotionRecipe.cpp

#include <string>
#include <vector>
#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
    : potionName(name), ingredients(ingredients) {}

std::string PotionRecipe::GetPotionName() const
{
    return potionName;
}

std::vector<std::string> PotionRecipe::GetIngredients() const
{
    return ingredients;
}