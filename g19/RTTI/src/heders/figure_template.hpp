#ifndef  FIGURE_TEMPLATE_HPP
#define  FIGURE_TEMPLATE_HPP
template<class T> class figure{
protected:
	T x, y;
public:
	;
	figure(T i, T j){
		x = i;
		y = j;
	}
	virtual T area() =0;//чистая виртуальная функция
};

template<class T> class triangle : public figure<T>{
	using figure<T>::x;
	using figure<T>::y;
public:
	triangle(T i, T j) : figure<T>(i, j){}
	T area(){
		return 0.5 * x * y;
	}
};

template<class T> class rectangle : public figure<T>{
	using figure<T>::x;
	using figure<T>::y;
public:
	rectangle(T i, T j) : figure<T>(i, j){}
	T area(){
		return x * y;
	}
};

template<class T> class circle : public figure<T>{
	using figure<T>::x;
	using figure<T>::y;
public:
	circle(T i, T j =0) : figure<T>(i,j){}
	T area(){
		return 3.14 * x * x;
	}
};

template<typename T> std::shared_ptr<figure<T>> factory(){
	switch(rand() % 3){
		case 0: return std::shared_ptr<figure<T>>(new circle<T>(rand()%100));
		case 1: return std::shared_ptr<figure<T>>(new triangle<T>(rand()%100, rand()%100));
		case 2: return std::shared_ptr<figure<T>>(new rectangle<T>(rand()%100, rand()%100));
	}
	return 0;
}
#endif //FIGURE_TEMPLATE_HPP