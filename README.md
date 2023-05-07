# DetectU
ECE3220 Final Project Kyle Peckenschneider, Grace Ogunbowale, and Gian Lucca Teixeira
Demo video link: https://youtu.be/MD87ds2tpdA

In this project, we used Qt for a graphical user interface to create an application of a webcam where you
are able to capture a photo, or record a video in which the recording file is saved to your computer.
To implent this, we used Qt API and implemented a stategy design pattern to switch between the operation of caputuring a photo
or recording. We also used a Singleton Strategy over the Record and Capture startegy classes because
only a single instance of the two were needed. Lastly, we implemented tests to ensure the program
runs without any bugs or exceptions.

# Stratgey Design Pattern
The Strategy design pattern is a behavioral design pattern that enables selecting an algorithm at runtime.
It does this by defining a family of algorithms and encapsulates them in objects.
And so, instead of implementing a single algorithm directly, code receives run-time instructions as to which in a family of algorithms to use.

## Example :
```C++

#include <iostream>
#include <memory>
#include <utility>

class Strategy {
public:
    virtual void execute() = 0;                           
    virtual ~Strategy() {}
};

class Context {
    std::unique_ptr<Strategy> strat{};                    
public:                                                   
    void setStrategy(std::unique_ptr<Strategy> strat_)  { 
        strat = std::move(strat_); }
    }
    void strategy()  { if (strat) strat->execute(); }     
};

class Strategy1 : public Strategy {
public:
    void execute() { std::cout << "Strategy1 executed\n"; }
};

class Strategy2 : public Strategy {
public:
    void execute() { std::cout << "Strategy2 executed\n"; }
};

class Strategy3 : public Strategy {
public:
    void execute() { std::cout << "Strategy3 executed\n"; }
};

int main() {

    std::cout << '\n';

    Context k;

    k.setStrategy(std::make_unique<Strategy1>());
    k.strategy();

    k.setStrategy(std::make_unique<Strategy2>());
    k.strategy();

    k.setStrategy(std::make_unique<Strategy3>());
    k.strategy();

    std::cout << '\n';

}
```
## Singleton
This pattern involves a single class which is responsible to create an object while making sure that only single object gets created. 
This class provides a way to access its only object which can be accessed directly without need to instantiate the object of the class.
## Example
```cpp

class Singleton{

  public: 
        static Singleton& getInstance(){
		static Singleton instance;
		return instance;
	}
        Singleton(Singleton const& ) = delete; // copy constructor;
        Singleton& operator=(Singleton const&) = delete; // copy assignment
        Singleton(Singleton &&) = delete; // move constructor
        Singleton& operator = (Singleton &&) = delete; // move assignment
        ~Singleton();
	void foo() { std::cout << __PRETTY_FUNCTION__ << std::endl;}
  private:
      Singleton(){}
}

int main(int argc, char* argv[]){

	// To get an instance of our singleton, we define a C++ reference variable and bind it to the
	// reference returned by the getInstance() method. That is, we give the singleton instance a name.
	Singleton &singleton_instance = Singleton::getInstance();
	singleton_instance.foo();
	
	return 0;
}
```

# QT
Qt is a cross-platform application development framework used to create software with graphical user interfaces (GUIs) and other types of applications.
It provides a comprehensive set of tools and libraries for creating applications that run on various operating systems, which we used 
including Windows, macOS, and Linux. For this project, we utilized the libraries of QVideoWidget, QMediaDevices,
QMediaCaptureSession, and QCamera which the documentation is provided under the reference tab. 
Qt is known for its ease of use, flexibility, and versatility, making it a popular choice among developers for creating applications for desktop, mobile, and embedded systems. It supports multiple programming languages, but for thisproject we only used C++.

# References
https://doc.qt.io/qt-6/qtmultimedia-camera-example.html

https://refactoring.guru/design-patterns/strategy/cpp/example

