#include <iostream>

using namespace std;

class ClassA {
	public:
	void function1A(){
		cout << "Hi." << endl;
		}
	void function2A(){
		cout << "Bye." << endl;
		}		
};

class ClassB {
	public:
	void function1B(){
		ClassA objectA;
		objectA.function1A();
		objectA.function2A();
	}
};

int main() {
	ClassB objectB;
	objectB.function1B();
	return 0;
}
