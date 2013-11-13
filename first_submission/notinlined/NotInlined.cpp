#include <iostream>
#include <memory>

class AbstractClass {
	public:
		virtual void cannotBeInlined()=0;
};

class DerivedClass : public AbstractClass {
	public:
		void cannotBeInlined() {
			std::cout << "Wooo!" << std::endl;
		}
};

int main() {
	std::unique_ptr<AbstractClass> d{new DerivedClass};
	d->cannotBeInlined();
}
