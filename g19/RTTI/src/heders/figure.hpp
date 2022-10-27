#ifndef FIGURE_HPP
#define FIGURE_HPP
namespace P{
class figure{
protected:
	double x, y;
public:
	figure(double i, double j) : x(i),y(j){}
	virtual double area() = 0;//чисто виртуальная функция
};

class triangle:public figure{
public:
	triangle(double i, double j) : figure(i,j){}
	double area() override {
		return 0.5 * x * y;
	}
};

class rectangle:public figure{
public:
	rectangle(double i, double j) : figure(i,j){}
	double area() override {
		return x * y;
	}
};

class circle : public figure{
public:
	circle(double i, double j=0) : figure(i,j){}
	double area() override {
		return 3.14 * x * x;
	}
};


std::shared_ptr<figure> factory(){
	switch(rand() % 3){
		case 0: return std::shared_ptr<figure>(new circle(rand()%100));
		case 1: return std::shared_ptr<figure>(new triangle(rand()%100, rand()%100));
		case 2: return std::shared_ptr<figure>(new rectangle(rand()%100, rand()%100));
	}
	return 0;
}

};
#endif //FIGURE_HPP