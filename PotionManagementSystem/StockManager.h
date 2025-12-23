// StockManager.h

#pragma once
#include <map>
#include <string>

class StockManager
{
public:
    static constexpr int MAX_STOCK = 3;
    
    // 초기 재고 3개 추가 메서드 선언
    void InitializeStock(const std::string& potionName);

    // 특정 물약의 현재 재고 수량 반환 메서드 선언
    int GetStock(const std::string& potionName) const;

    // 재고가 1개 이상인 경우 모험가에게 물약 지급 메서드 선언
    bool DispensePotion(const std::string& potionName);

    // 모험가에게 지급한 물약의 공병 반환 받는 메서드 선언
    void ReturnPotion(const std::string& potionName);



private:
    // 포션 재고
    std::map <const std::string, int> potionStock;
};