// AlchemyWorkshop.cpp

#include <iostream>
#include <string>
#include <vector>
#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
    recipes.push_back(PotionRecipe(name, ingredients));
    recipeMap[name] = ingredients;

    // 재료별로 레시피명을 인덱싱
    for (const auto& ing : ingredients)
    {
        ingredientMap[ing].push_back(name);
    }

    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

// 모든 레시피 출력 메서드
void AlchemyWorkshop::displayAllRecipes() const {
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        std::cout << "- 물약 이름: " << recipes[i].GetPotionName() << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].GetIngredients().size(); ++j) {
            std::cout << recipes[i].GetIngredients()[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].GetIngredients().size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

// 특정 물약의 레시피 검색 메서드
PotionRecipe AlchemyWorkshop::searchRecipeByName(const std::string& name) const
{
    auto it = recipeMap.find(name);

    if (it != recipeMap.end())
    {
        PotionRecipe recipe(it->first, it->second);
        return recipe;
    } 
    else 
    {
        std::cout << "검색어: [" << name << "]에 해당되는 레시피가 없습니다.\n";
    }

    return PotionRecipe("", {}); // 빈 레시피 반환
}

// 특정 재료의 모든 물약 레시피 검색 메서드
std::vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(const std::string& ingredient) const
{
    std::vector<PotionRecipe> recipes;

    auto it = ingredientMap.find(ingredient);
    if (it == ingredientMap.end())
    {
        std::cout << "검색어: [" << ingredient << "] 재료가 들어간 레시피가 없습니다.\n";
        return recipes;
    }

    for (const auto& name : it->second)
    {
        auto recipe = recipeMap.find(name);
        if (recipe != recipeMap.end())
        {
            recipes.emplace_back(recipe->first, recipe->second);
        }
    }

    return recipes;
}