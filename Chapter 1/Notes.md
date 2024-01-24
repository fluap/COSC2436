# 1.  Data Abstraction: The walls.

## Object - Oriented Concepts
### Object-Oriented Analysis and Design
**O**bject **o**riented **a**nalysis and **d**esign (OOAD) is a problem solving methodology in **O**bject **O**riented **P**rogramming (OOP). The program provides a *solution* consisting of interacting *objects* that belong to the same and different *classes*.

Each *object* is an instantiatied version of a *class* and has defined characteristics (attributes) and behaviors (methods).

### Object Oriented Analysis 
The expression of the problem and its required solutions in terms of objects that pertain to it. (pertain to the problem).

Analysis is done on the problem itself and not the solution for it. 

### Object Oriented Design
A description of the solution to a problem. The solution is described in terms of software objects and their interactions (*Collaboration*)
**This is essentially the modeling of a solution (the program).**


### Aspects of an object-oriented Solution
**Module:** A self contained unit of code.

*This definition is flexible in practice, details for why.* 
<details> A module varies from a single function or class, to several blocks of code. Typically speaking, a module tends to be several blocks of code that have a thematic purpose: ie math modules perform several different mathematical operations.
</details>

Modules are used to store, move, and alter data. 

**Object:** an instantiated *thing* (class) with attributes and *behaviors* (methods, member functions, potato-potahtoe).

**Encapsulation:** A technique that hides inner details. 
<details>
Much like functions hide the inner details of how they work, classes (and therefore objects) hide their methodologies as well. Classes also have the ability to hide data (attributes of their objects).
</details>
<br>
**Inheritance:** the absorption of properties and behaviors from another *parent* class.

<br>
<details>

```c
class cVehicle{
    bool floats;
    bool flies;
    bool rolls;
    bool toopoorforavehicle = true;
}
class cVehicle : cCar{  //cCar inherits cVehicle
    int wheels = 4;
    float horsepower;
}
```
Class A is a vehicle.
Class B is a sports car.
Class B could inherit all of class A's attributes and still be a sports car. Therefore, it would be a good idea to have Class B inherit from class A, and build upon that inheritance, rather than rebuilding another class from scratch.
[More on inheritance...](https://www.geeksforgeeks.org/inheritance-in-c/)
</details>
<br>

**Polymorphism:** a way of determining what its needed at *runtime* rather than *execution time*

<details>

[Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/) is detailed, so i'll start with the link first as my details wont cover the full scope (or even come close).

If a class inherits from another class, it can redefine the parent class' function(s). This means that during runtime, if an object is created from the inherited class, its functions are polymorphosized (real word had to check) and will behave according to *its* class.

```c
class cNormalPeople{
    int add2(int x){
        return x + 2;
    }
class cNormalPeople : cMe{
    int add2(int x); //Overrides add2 from cNormalPeople
    return x + 3;
}
cNormalPeople A;
cMe B; //polymorphosized
```

</details>
___
### Achieving a Better Solution
**Cohesion:** The *art* of having a module perform a single task properly. 

Cohesion is a distributive definition meaning something can range from *highly cohesive* (single task, well bounded, easily identifyable objective), to lowly cohesive (multiple tasks, intertwined with other functionality, *undeterminable objective*)
<details>
The most common form of cohesion I see is when someone prints something (like a result) rather than returning it.

While often overlooked, the act of printing a result is the *addition* of another task, reducing the cohesiveness of the function or method.
</details>

<br> 

**Coupling:** This is a measure of module's dependence on eachother. 
- **Loosely coupled:** Modules that are nearly independent from one another. 
- **Highly coupled:** Modules that are nearly dependent on one another.

<details>

*story explanation*

I remember when I was a kid, I had this RC car. The remote literally had a single trigger with nothing else (other than the power switch) on it.

When I'd turn it on, the car would go in reverse and and rotate counter clockwise. Only when I pulled the trigger on the remote would it then go forward and in a straight line.  Making a right hand turn with this thing meant a 270 degree spin in reverse, and a well timed trigger pull to straighten out. 
Fun times...  

The relationship between turning and reverse were coupled. This is because to turn, you had to be going backwards.  
Decoupling the two functions would have made me a better driver (and it, a better RC car).

</details>

Its worth mentioning that a minimal amount of coupling is required for independent modules to actually work. That being said *minimal* coupling is what a programmer should strive for, rather than the 'on-paper' model of complete independence.
___
### Specifications
A **Specification** is a statement on what something does, without including detail as to how it does it.

**Operation Contract:** Documentation specifying how a method can be used and what limitations it has. Documentation is developed during analysis and design, and finalized in the contract of the code (usually in the header file).

**Method interface:** Documentation specifying how to use the function. 
- Datatypes
- Arguments
- Order
- Assumptions
- Input validation
- Error handling
- Execution

The method interface is a part of the contract and is often seen when declaring prototype functions.

From a high level, contracts are broken into two types of conditions::

- **Precondition:** Everything a programmer needs to know prior to the execution of the function.
- **Postcondition:** Everything a programmer needs to know after the execution of a function.

**Unusual Conditions:** Are essentially a (input) validation / error handling thought process on how to cover unexpected or undesirable behavior occuring with the method.

### Abstraction

Up to this point, all the strategies fall into the concept of **abstraction**. Essentially, the less each part of the code 'needs to know' the more abstract it is. In practice, more abstract code tends to be more readable, however the required volume of code can potentially lead to some performance drawbacks. Regardless, complex programs require sometimes hundreds of people to work on it at the same time and therefore abstraction wins in overall production due to the benefits come with its understandability across a team of programmers.

<br>
(Example: Data Abstraction)
<details>

The gas tank needle in your car is a good form of **data abstraction**. Drivers use the needle to determine when to get gas, but never truly know exactly how much gas is in their car, and frankly don't need to!

</details>
<br>
(Example: Information Hiding)
<details>

Many drivers dont actually know how the gas in their car is measured. The technology that is in charge of calulating and reporting the amount left is a mystery to most drivers! Regardless, the tool serves its purpose, and no details are required.

</details>
<br>

**Minimal and Complete Interfaces** (interface = class)

- **Minimal:** These are classes that contain few method(s) that are essential to the class.
- **Complete:** This interface allows programmers to accomplish any reasonable task within the class' scope of responsibility.

Complete and Minimal interfaces go hand in hand. That is, a class should be as complete and as minimal as possible (no bloat, keep cohesion in mind).
___
### Abstract datatypes
Not to be confused with a data-structure, an abstract datatype (ADT) is a collection of data, and a set of operations that can be performed on it.

Operations can fall under categories such as: 

- **Add** data to a data collection.
- **Remove** data from a data collection.
- **Ask** questions about the data in a data collection.


A collection of data can be built by pre-defined or abstract data-structures. These structures can be:
- Arrays
- Objects
- Structs (dictionaries)
- Directories (kinda, ignore if confusing)

Note: ADT specifications *also* do not include the *how*. They must only include the *need*. The ADT's **implementation** however, *does* specify the how, in it's own documentation (abstraction abstraction abstraction).

<details>

The gas pedal in your car makes it go forward, or backwards. (hopefully not sideways). That is the ADT specification is the *need* is for the car to move when the pedal is pressed. (ie: This is a rectangle you can shove your foot into to make the car move). The ADT's **implementation** can be much more detailed. (The cable pulled by the gas pedal allows more air/fuel mixture into the engine, causing it to produce more power from increased rate of combustion)

</details>

___
### The ADT Bag
Long example made short, the ADT bag is a metaphorical and literal bag. (It's an analogy) The bag can contain a max number of items, and only certain items. The bag can have items added to it, taken out of it, and you can look in the bag to see whats in there. What you dont know about the bag, is how its carrying the items inside. (sometimes you do care how, but for the sake of the example, its trying to explain that each ADT will have aspects about it that are not required to be known.)
