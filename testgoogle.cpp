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
};

class ShoppingCart{
 private:
std::vector<item> basket;
 public:
 void addItem(item a){basket.push_back(a);}
  int findItem(item a){
    for(int i = 0; i < basket.size(); i++){
      if(basket[i] == a){
	return i;
      }
    }
  }
  void removeItem(item a){basket.erase(findItem(name));}
 float total(){
   float t;
   if(basket.empty()){
     return 0;
   }
   for(int i = 0; i < basket.size(); i++){
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
    if(ispercentage){
      float s; // for subtrahend
      for(int i = 0; i < cart.basket.size(); i++){
	s = cart.basket[i].price *  discountAmount;
	basket[i] -= s;
      }
      
    } else{
      basket[i] -= discountAmount;
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
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  
}
