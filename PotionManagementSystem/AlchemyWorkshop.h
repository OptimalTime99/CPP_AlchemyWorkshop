// AlchemyWorkshop.h

#pragma once
#include <map>
#include <string>
#include <vector>
#include "StockManager.h"
#include "PotionRecipe.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void AddRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void DisplayAllRecipes() const;

    // searchRecipeByName 메서드: 물약 이름(string)을 매개변수로 받아 레시피 검색하는 기능 추가
    PotionRecipe SearchRecipeByName(const std::string& name);

    // searchRecipeByIngredient 메서드: 재료(string)를 매개변수로 받아 레시피 검색하는 기능 추가
    std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const;

    // 특정 물약의 현재 재고 수량 반환 메서드
    int GetPotionStock(const std::string& potionName);

    // 재고가 1개 이상인 경우 모험가에게 물약 지급 메서드 선언
    bool DispensePotion(const std::string& potionName);

    // 모험가에게 지급한 물약의 공병 반환 메서드
    void ReturnPotionBottle(const std::string& potionName);

private:
    std::vector<PotionRecipe> recipes;

    std::map <std::string, std::vector<std::string>> recipeMap;

    std::map <std::string, std::vector<std::string>> ingredientMap;

    StockManager stockManager;
};
