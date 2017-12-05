/*
  CtorInheritancePract:
    Practice using initilization lists in the constructor.
    Not much code is changed other than passing parameter arguments to the
    constructors of the class
*/

#include <iostream>
using namespace std;


/*
  Private Inheritance example
*/

class Fish
{
  public:
    //normally in initilization list
    Fish(bool isFreshWater): FreshWaterFish(isFreshWater){}

    void Swim()
    {
      if(FreshWaterFish)
        cout << "Swims in a lake" << endl;
      else
        cout << "Swims in the sea" << endl;
    }

  protected:
    bool FreshWaterFish;
};

class Tuna: public Fish
{
  public:
    Tuna(): Fish(false) {}
};

class Carp: public Fish
{
  public:
    Carp(): Fish(true) {};
};

int main()
{
  Carp myLunch;
  Tuna myDinner;

  cout << "Lunch:" << endl;
  myLunch.Swim();

  cout << "Dinner:" << endl;
  myDinner.Swim();

  myDinner.Fish::Swim();

  //uncomment to see compilation error
  //myLunch.FreshWaterFish = false;
  return 0;
}
