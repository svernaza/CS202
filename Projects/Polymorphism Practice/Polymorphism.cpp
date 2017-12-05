#include <iostream>
using namespace std;

class Fish
{
public:

  //original declaration ommited virtual
  //void Swim()
  //new declaration
  virtual void Swim()
  {
    cout << "Fish Swims!" << endl;
  }
};

class Tuna:public Fish
{
public:
  //override Fish::Swims
  void Swim()
  {
    cout << "Tuna Swims!" << endl;
  }
};

//Class Carp (demonstrates the use of virtual function)
class Carp:public Fish
{
public:
  void Swim()
  {
    cout << "Carp Swims!" << endl;
  }
};
void MakeFishSwim(Fish& InputFish)
{
  //calling virtual method Swim
  InputFish.Swim();
}

int main()
{
  Tuna myDinner;
  Carp myLunch;

  //sending Tuna as a Fish
  MakeFishSwim(myDinner);
  //sending Carp as Fish
  MakeFishSwim(myLunch);

  return 0;
}
