// AlchemyWorkshop.h

#pragma once
#include <map>
#include <string>
#include <vector>
#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // searchRecipeByName 메서드: 물약 이름(string)을 매개변수로 받아 레시피 검색하는 기능 추가
    PotionRecipe searchRecipeByName(const std::string& name) const;

    // searchRecipeByIngredient 메서드: 재료(string)를 매개변수로 받아 레시피 검색하는 기능 추가
    std::vector<PotionRecipe> searchRecipeByIngredient(const std::string& ingredient) const;

private:
    std::vector<PotionRecipe> recipes;

    std::map <std::string, std::vector<std::string>> recipeMap;
};
