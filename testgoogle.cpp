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
