#include <string>
#include "StockManager.h"

// 초기 재고 3개 추가 메서드 정의
void StockManager::InitializeStock(const std::string& potionName)
{
    potionStock[potionName] = 3;
}

// 특정 물약의 현재 재고 수량 반환 메서드 정의
int StockManager::GetStock(const std::string& potionName) const
{
    auto it = potionStock.find(potionName);

    return (it != potionStock.end()) ? it->second : 0;
}

// 재고가 1개 이상인 경우 모험가에게 물약 지급 메서드 정의
bool StockManager::DispensePotion(const std::string& potionName)
{
    if (potionStock[potionName] > 0)
    {
        --potionStock[potionName];
        return true;
    }

    return false;
}

// 모험가에게 지급한 물약의 공병 반환 받는 메서드 정의
void StockManager::ReturnPotion(const std::string& potionName)
{
    if (potionStock[potionName] < MAX_STOCK)
    {
        ++potionStock[potionName];
    }
}