#include <iostream>
#define interface class

interface Shape {
public:
	// draw()함수를 선언만 하였다.
	virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
	// interface에서 선언한 draw를 Rectangle class에 맞게 구현하였다.
	void draw() {
		std::cout << "Shape: Rectangle" << std::endl;
	}
};

class Circle : public Shape {
public:
	// interface에서 선언한 draw를 Circle class에 맞게 구현하였다.
	void draw() {
		std::cout << "Shape: Circle" << std::endl;
	}
};

class ShapeDecorator : public Shape {
protected:
	Shape* decoratedShape;
public:
	// shape를 입력받아 초기화하는 생성자이다.
	ShapeDecorator(Shape* _decoratedShape) {
		decoratedShape = _decoratedShape;
	}
	// interface에서 선언한 draw를 ShapeDecorator에서 선택한 도형에 맞게 출력한다.
	void draw() {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {
public:
	RedShapeDecorator(Shape* _decoratedShape) : ShapeDecorator(_decoratedShape) {}

	//
	void draw() {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}

private:
	// Shape의 테두리를 빨간색으로 바꾸는 함수이다. 여기서는 출력만 하도록 구현하였다.
	void setRedBorder(Shape* decoratedShape) {
		std::cout << "Border Color: Red" << std::endl;
	}
};

int main() {
	Shape* circle = new Circle();
	Shape* redCircle = new RedShapeDecorator(new Circle);
	Shape* redRectangle = new RedShapeDecorator(new Rectangle);

	std::cout << "Circle with normal border" << std::endl;
	circle->draw();

	std::cout << "\nCircle of red border" << std::endl;
	redCircle->draw();

	std::cout << "\nRectangle of red border" << std::endl;
	redRectangle->draw();

	return 0;

}
