#include <iostream>


// Some constants
const double G_EARTH = 9.81;
const double AU_EARTH = 1.0;


// Base Class
class Planet{
    
  /* friend Functions & Classes */
  friend std::ostream& operator<<(std::ostream& os, const Planet& p){ 
    os << "Planet: " << p.m_G << " " << p.m_AU;
  }

  /*
   * Notice here how the ctor & dtor of the Base class are placed under the protected access specification level. This means that to any EXTERNAL USER of the class they are inaccessible (as if private)
   * which means that they cannot be called to instantiate a Planet object! This essentially makes this Base class only a baseline (a kind of incomplete template at the top of an inheritance hierarchy)
   * to build other specialized (Derived) classes from, and prevent any mindless user from accidentally instantiating an object of this functionality-wise incomplete class.
   * Note1: By having declared a Parametrized-ctor, no Default-ctor will be automatically synthesized by the compiler - therefore a user is prevented from instantiating this way too.
   * Note2: Eventually, by having a protected dtor means that even if a Base object existed, it could not be destroyed from an EXTERNAL USER (only a Derived class is able to call the Base dtor since
   *        is is protected) and therefore the compiler will not even allow an automatically-synthesized Copy-ctor to be called since it would imply the ability to create a Planet object (which would
   *        subsequently be unable to be destroyed).
   *        However, the automatically-synthesized Base class Copy-ctor will be accesible to call from a Derived class (exactly because the Derived class is enabled to call the Base dtor when it is
   *        time to destroy its resources) which means that the automatically-synthesized Derived class Copy-ctor will use it.
   * Note3: Finally, the automatically synthesized Assignment operator cannot be allowed since we have const data members (assignment of consts is not allowed).
   *        Even if the members were not const, an automatically-synthesized operator= would perform value-copy assignment to the members of the Base class Planet, therefore a mistake would be to do:
   *        Derived d1, d2;                   // Two Derived class objects 
   *        Base *d1_pt = &d1, *d2_pt = &d2;  // Two Base class pointers pointing to the previous two Derived class objects (perfectly allowed) 
   *        *d1_pt = *d2_pt;                  // Assignment performed on objects dereferenced from Base class pointers (original objects are Derived class types, but calling operator= with Base class
   *                                          // pointers will make the compiler choose the Base class assignment (member-copy ONLY the Base class data members and ommit any Derived class ones)
   *        d1 = d2;                          // On the other hand, Assignment performed on objects of Derived class type will make the compiler choose the Derived class assignment which (the 
   *                                          // automatically-synthesized one) will member-copy both the data of the Derived class and the data of the Base class 
   *        Therefore a publicly exposed (the automatically-synthesized Assignment operator is public) would enable partial assignment (Base class members only) of data if used on Derived class objecs
   *        through Base class pointers, so we also choose to define it and declare is as protected (cannot be called by any ETERNAL USER or the class but can be used by a Derived class method such
   *        as the Derived class automatically-synthesized Assignment operator=)   
   */
  protected:

    // Parametrized-ctor, takes in parameters which allow it to use them in an initializer list to initialize const data members at-instatiation. */ 
    Planet(double g, double au=1.0) :
      m_G( g>=0.0 ? g : 0.0 ) ,  // Ternary operator evaluates to an expression: case (g) or case (0) depending on whether (g>=0) is true/false, allows to control the value passed for initialization 
      m_AU( au>=0.0 ? au : 0.0 ) // Same logic here, essentially this never lets a negative value to be used to initialize the const members m_G and m_AU
    {
      std::cout << "Planet ctor" << std::endl;  // Just a debug statement for the Base class ctor
    }

    ~Planet()
    {
      std::cout << "Planet dtor" << std::endl;  // Just a debug statement for the Base class dtor
    }

    Planet& operator=(const Planet& rhs){
      if (this != &rhs){
        // do nothing because in this example all data members are const
        std::cout << "Planet assignment" << std::endl;  // Just a debug statement for the Base class assignment
      }
      return *this;
    }
 
    const double m_AU;   
 
  private:

    const double m_G;   

};


// Derived Class
class Earth : public Planet{

  /* Note here how we implement the overload for Earth to preform its own functionality (prints out private "Earth", could also be printing out any private data of the Derived class), but if we also
   * want to it print out all the members it inherits from Base class Planet, we would either do:
   * a) os << m_AU; // OK! Direct access to protected Base class member m_AU
   *    os << m_G;  // BAD! No access to private Base class member m_G (also, no GetG() function exists!)
   * b) But, after we are done outputting the Derived class data (extensions of the Base class) we can call upon the insertion operator overload for a Base class object by CASTING the (const Earth&)
   *    we receive to a (const Planet&) and feeding it to the insertion operator - this will call now the Base class overload which is implemented as a friend of Planet and outputs the m_G, m_AU data.
   */ 
  /* friend Functions & Classes */
  friend std::ostream& operator<<(std::ostream& os, const Earth& e){ 
    os << "Earth: " << static_cast<const Planet&>(e) ;
  }

  /* The Derived classes (as opposed to the Base class) have to expose public ctor(s) / dtor, otherwise they cannot be instantiated */
  public:

    /* 
     * Note here how the Derived class ctor invokes the Base class ctor through the initialization list method (this is the only way to invoke a Base class ctor from a Derived class ctor)
     * This allows to:
     *  a) Re-use a behavior which is already properly implemented in the Base class.
     *  b) Initialize const members of the Base class to specific values by specifying arguments for the Base ctor or by forwarding arguments from the Derived ctor to the Base ctor.
     *  c) Even if the members were not const, m_G is private and would therefore be inaccessible directly from the Derived class (we would need a SetG() to modify it).
     */ 
    // Only a Default-ctor for Earth objects, m_G and m_AU initialized to specific constants
    Earth() :
      Planet(G_EARTH, AU_EARTH)
    {
      std::cout << "Earth ctor" << std::endl;  // Just a debug statement for the Derived class ctor
    }
 
    ~Earth()
    {
      std::cout << "Earth dtor" << std::endl;  // Just a debug statement for the Derived class dtor
    }  
    
};


// Another Derived Class
class SolarSystemPlanet : public Planet{

  /* friend Functions & Classes */
  friend std::ostream& operator<<(std::ostream& os, const SolarSystemPlanet& ssp){ 
    os << "SolarSystemPlanet: " << static_cast<const Planet&>(ssp) ;
  }

  /* The Derived classes (as opposed to the Base class) have to expose public ctor(s) / dtor, otherwise they cannot be instantiated. */
  public:

    // A Parametrized-ctor for SolarSystemPlanet objects, arguments for g and au are forwarded to Planet ctor (Base class ctor) to initialize data members m_G and m_AU at instantiation
    SolarSystemPlanet(double g, double au) :
      Planet(g, au)
    {
      std::cout << "SolarSystemPlanet ctor" << std::endl;  // Just a debug statement for the Derived class ctor
    }
 
    ~SolarSystemPlanet()
    {
      std::cout << "SolarSystemPlanet dtor" << std::endl;  // Just a debug statement for the Derived class dtor 
    }  

};


int main()
{
  /* Expect to see ctor(s) called in order: Base-ctor -> Derived-ctor */

  std::cout << std::endl << "Testing Earth" << std::endl;
  Earth earth;
  std::cout << earth << std::endl;

  /*
   * As noted in the class Planet, this will not compile because ctor & dtor of Base class are protected
   */
  //Planet planet_0(1.52, 3.77);

  std::cout << std::endl << "Testing SolarSystemPlanet" << std::endl;
  SolarSystemPlanet solar_system_planet_X(1.52, 3.77);
  std::cout << solar_system_planet_X << std::endl;

  std::cout << std::endl << "Testing SolarSystemPlanet Copy" << std::endl;
  SolarSystemPlanet solar_system_planet_cpy( solar_system_planet_X );
  std::cout << solar_system_planet_cpy << std::endl;


  //////////////////
  ///// EXTRAS /////
  //////////////////
  std::cout << std::endl << "Testing Extras" << std::endl;
  /*
   * Base class pointers pointed to Derived class objects (perfectly allowed)
   */
  Planet *e_p = &earth;
  Planet *ss_p = &solar_system_planet_X;
  /*
   * As noted in the class Planet, this will not compile because Assignment operator= of the Base class is protected
   * If it wasn't (and if the data members were not const so that we could assigne to them ) this would call the Base class Assignment operator= which would only perform assignment of Base class data 
   * members (partial assignment of Base class members onlt on a Derived class object) which is most probably an undesired behavior
   */
  //*ss_p = *e_p;
 
  /*
   * Derived class Assignment operator= is not defined (but automatically-synthesized for the Derived class) which will use the Base class Assignment operator= (it is allowed to use it since it is 
   * protected in the Base class and the Derived class has access to it).
   */
  SolarSystemPlanet solar_system_planet_assign(-1.0, -100.0);  // Arguments passed to Derived class Parametrized ctor will be forwarded to Base class ctor whose initialization list will not allow
                                                               // negative values to initialize the m_G and m_AU data members

  solar_system_planet_assign = solar_system_planet_X;


  std::cout << std::endl << "Tests Done" << std::endl;
  /* Expect to see ctor(s) called in order: Derived-dtor -> Base-ctor */

  return 0;
}

