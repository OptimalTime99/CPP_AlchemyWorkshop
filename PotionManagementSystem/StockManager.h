// StockManager.h

#pragma once
#include <map>
#include <string>

class StockManager
{
public:
    
    // 초기 재고 3개 추가 메서드 선언
    void initializeStock(std::string potionName);

    // 특정 물약의 현재 재고 수량 반환 메서드 선언
    int getStock(std::string potionName);

    // 재고가 1개 이상인 경우 모험가에게 물약 지급 메서드 선언
    bool dispensePotion(std::string potionName);

    // 모험가에게 지급한 물약의 공병 반환 받는 메서드 선언
    void returnPotion(std::string potionName);

private:
    // 포션 재고
    std::map <std::string, int> potionStock;

    // 최대 포션 재고
    const int MAX_STOCK = 3;
};