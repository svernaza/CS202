
/*
  Private Inheritance example:
    When declaring a protected class you are only allowing access to the classes
    that derive adn friends yet making it inaccessible to everyone else outside,
    including main!
*/

#include <iostream>
using namespace std;

class Fish
{
  protected:
    bool FreshWaterFish; //accesseible only to derived classes

  public:
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

  //uncomment the following in order see that protected members aren't
  //accessible from outide the class hierarchy
  //myLunch.FreshWaterFish = false;
  return 0;
}
