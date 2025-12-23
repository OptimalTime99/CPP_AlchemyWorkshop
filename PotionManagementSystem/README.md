## **주어진 클래스, 데이터, 함수**

### **물약 공방 클래스: `AIchemyWorkShop`**

```
-   데이터
    -   레시피 모음: `std::vector<PotionRecipe> recipes`
-   함수
    -   레시피 추가 기능: `void addRecipe(std::string potionName, std::string coreIngredient)`
        -   포션명: potionName
        -   핵심 재료: coreIngredient
    -   모든 레시피 보기 기능: `void displayAllRecipes()`
```

### **포션 레시피 클래스: `PotionRecipe`**

```
-   데이터
    -   포션명: `std::string potionName`
        -   핵심 재료: `std::string coreIngredient`
-   생성자
    -   `PotionRecipe(std::string potionName, std::string coreIngredient)`
-   함수
    -   하나의 레시피 보기 기능: `void displayRecipes()`
```

물약 공방 클래스는 포션 레시피 데이터를 관리한다.

---

## **필수 기능**

-   기존 연금술 공방 관리 시스템에 검색 기능 추가: 풀네임이 같은 경우 기준으로 검색한다.
    -   물약 이름(string)을 매개변수로 받아 레시피 검색하는 기능 추가
        -   `PotionRecipe searchRecipeByName(const std::string& name) const`
    -   searchRecipeByIngredient 메서드: 재료(string)를 매개변수로 받아 레시피 검색하는 기능 추가
        -   `std::vector<PotionRecipe> searchRecipeByIngredient(const std::string& ingredient) const`
    -   물약 이름이 동일한 경우는 없다고 가정한다  
        → map을 통해 빠르게 검색해도 괜찮다.

### **물약 공방 클래스: `AIchemyWorkShop`**

```
-   데이터
    -   레시피 모음: `std::vector<PotionRecipe> recipes`
    -    레시피 맵(검색용): `std::map <std::string, std::vector<std::string>> recipeMap`
    -   재료 레시피맵(검색용): `std::map <std::string, std::vector<std::string>> ingredientMap`
-   함수
    -   레시피 추가 기능: `void addRecipe(const std::string& name, const std::vector<std::string>& ingredients)`
           -   포션명: potionName
        -   핵심 재료: coreIngredient
    -   모든 레시피 보기 기능: `void displayAllRecipes() const`
    -     특정 레시피명 검색 기능: `PotionRecipe searchRecipeByName(const std::string& name) const`
    -   특정 재료로 레시피명 검색 기능: `std::vector<PotionRecipe> searchRecipeByIngredient(const std::string& ingredient) const`
```

### **포션 레시피 클래스: `PotionRecipe`**

```
-   데이터
    -   포션명: `std::string potionName`
    -   핵심 재료: `std::string coreIngredient`
-   생성자
    -   `PotionRecipe(std::string potionName, std::string coreIngredient)`
-   함수
    -   포션명 반환 기능: `std::string GetPotionName() const`
    -    재료 목록 반환 기능: `std::vector<std::string> GetIngredients() const`
```

`(const std::string& 매개변수명)`

-   문자열 객체를 복사 없이 받아서, 읽기 전용으로 사용하겠다

---

## **도전 기능**

### **물약 공방 클래스: `AIchemyWorkShop`**

```
-   데이터
    -   레시피 모음: `std::vector<PotionRecipe> recipes`
    -    레시피 맵(검색용): `std::map <std::string, std::vector<std::string>> recipeMap`
    -   재료 레시피맵(검색용): `std::map <std::string, std::vector<std::string>> ingredientMap`
-   함수
    -   레시피 추가 기능: `void addRecipe(const std::string& name, const std::vector<std::string>& ingredients)`
           -   포션명: potionName
        -   핵심 재료: coreIngredient
    -   모든 레시피 보기 기능: `void displayAllRecipes() const`
    -     특정 레시피명 검색 기능: `PotionRecipe searchRecipeByName(const std::string& name) const`
    -   특정 재료로 레시피명 검색 기능: `std::vector<PotionRecipe> searchRecipeByIngredient(const std::string& ingredient) const`
```

### **포션 레시피 클래스: `PotionRecipe`**

```
-   데이터
    -   포션명: `std::string potionName`
    -   핵심 재료: `std::string coreIngredient`
-   생성자
    -   `PotionRecipe(std::string potionName, std::string coreIngredient)`
-   함수
    -   포션명 반환 기능: `std::string GetPotionName() const`
    -    재료 목록 반환 기능: `std::vector<std::string> GetIngredients() const`
```

### **재고 클래스: `StockManager`**

```
- 데이터
    - 재고: `std::map<std::string, int> potionStock`
    - 최대 재고: `const int MAX_STOCK = 3`
- 함수
    - 초기 재고 3개 추가: `void initializeStock(std::string potionName)`
        - 물약 공방 클래스의 addRecipe 함수 실행 후 initializeStock 함수 실행
    - 특정 물약의 현재 재고 수량 반환: `int getStock(std::string potionName) const`
    - 재고가 1개 이상인 경우 지급: `bool dispensePotion(std::string potionName)`
        - 물약 공방 클래스의 searchRecipeByName 함수 실행 후 레시피가 있으면 dispensePotion 함수 실행
    - 지급한 물약의 공병 반환 받기: `void returnPotion(std::string potionName)`
```
- 포션을 모험가에게 지급/반환하는 기능이 있는 것으로 봐서 모험가 클래스에 대한 추가를 염두에 두고 구현해야 함.