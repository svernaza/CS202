/*
  General Syntax:
    class Base
    {
      //...base class members
    };

    class Derived: access-specifier base
    {
      //...derived class members
    };
*/

//public inheritance example
#include <iostream>
using namespace std;

//base class
class Fish
{
  public:
    bool FreshWaterFish;

    void Swim()
    {
      if(FreshWaterFish)
        cout << "Swims in a lake" << endl;
      else
        cout << "Swims in the sea" << endl;
    }
};

class Tuna: public Fish
{
  public:
    Tuna()
      {
        FreshWaterFish = false;
      }
};

class Carp: public Fish
{
  public:
    Carp()
      {
        FreshWaterFish = true;
      }
};

int main()
{
  Carp myLunch;
  Tuna myDinner;

  cout << "Lunch:" << endl;
  myLunch.Swim();

  cout << "Dinner:" << endl;
  myDinner.Swim();
  return 0;
}
