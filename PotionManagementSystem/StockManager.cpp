#include <string>
#include "StockManager.h"

// 초기 재고 3개 추가 메서드 정의
void StockManager::initializeStock(std::string potionName)
{

}

// 특정 물약의 현재 재고 수량 반환 메서드 정의
int StockManager::getStock(std::string potionName)
{
    return 1;
}

// 재고가 1개 이상인 경우 모험가에게 물약 지급 메서드 정의
bool StockManager::dispensePotion(std::string potionName)
{
    return true;
}

// 모험가에게 지급한 물약의 공병 반환 받는 메서드 정의
void StockManager::returnPotion(std::string potionName)
{

}