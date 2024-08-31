#include <iostream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>

std::string rever(std::string input){
  std::reverse(input.begin(), input.end());
  return input;
}

struct item{
  std::string name;
  float price;

    // Overload the == operator for item comparison
  bool operator==(const item& other) const {
    return name == other.name && price == other.price;
  }
};



class ShoppingCart{
 private:

 public:
 std::vector<item> basket;
 void addItem(item a){basket.push_back(a);}
  int findItem(item a){
    for(size_t i = 0; i < basket.size(); i++){
      if(basket[i] == a){
	return i;
      }
    }
  }
  void removeItem(item a){basket.erase(basket.begin() + findItem(a));}
 float total(){
   float t;
   if(basket.empty()){
     return 0;
   }
   for(size_t i = 0; i < basket.size(); i++){
     t += basket[i].price;
   }
   return t;
 }
  float fetchPrice(item a){return basket[findItem(a)].price;}
};

class Discount{
private:
  double discountAmount;
  bool isPercentage;
public:
  Discount(double da, bool ip){
    discountAmount = da;
    isPercentage = ip;
  }
  double getDiscountAmount(){return discountAmount;}
  bool isPercentageDiscount(){return isPercentage;}
  void applyDiscount(ShoppingCart& cart){
    if(isPercentage){
      float s; // for subtrahend
      for(size_t i = 0; i < cart.basket.size(); i++){
	s = cart.basket[i].price *  (discountAmount / 100);
	cart.basket[i].price -= s;
	//std::cout << "SANITY CHECK RAAAAH\n";
	
      }
      
    } else{
       for(size_t i = 0; i < cart.basket.size(); i++){
	 cart.basket[i].price -= discountAmount;
       }
    }
  }
  
};


TEST(Test, Unit){
  EXPECT_EQ(rever("hello"), "olleh");
  }


TEST(Test, Integration){
  ShoppingCart target;
  EXPECT_EQ(target.total(), 0);
  item shirt;
  shirt.name = "shirt";
  shirt.price = 10;
  target.addItem(shirt);
  item shirt2;
  shirt2.name = "shirt";
  shirt.price = 20;
  target.addItem(shirt);
  EXPECT_EQ(target.total(), 30);
  
}


TEST(Test, DiscountPercent){ //doesn't really fit the above naming scheme
    ShoppingCart target;
    item shirt;
    shirt.name = "shirt";
    shirt.price = 10;
    target.addItem(shirt);
    Discount fiftyOff(50, true);

    EXPECT_EQ(fiftyOff.getDiscountAmount(), 50);
    EXPECT_EQ(fiftyOff.isPercentageDiscount(), true);
    fiftyOff.applyDiscount(target);
    EXPECT_EQ(target.total(), 5);
}

TEST(Test, DiscountFlatAmount){
    ShoppingCart target;
    item shirt;
    shirt.name = "shirt";
    shirt.price = 10;
    target.addItem(shirt);
    Discount fiveOff(5, false);

    EXPECT_EQ(fiveOff.getDiscountAmount(), 5);
    EXPECT_EQ(fiveOff.isPercentageDiscount(), false);
    fiveOff.applyDiscount(target);
    EXPECT_EQ(target.total(), 5);
}


    
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  
}
