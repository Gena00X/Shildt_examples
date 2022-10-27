#include <iostream>
using namespace std;
//1 byte = 8 bites (00000000)
//платформозависимая реализация если в байте не 8 бит работать не будет
const int bits_in_byte = 8;

//функция печати числа по битам (работает в пределах одного машинного слова (32/64 бит))
template<class T> void d_bin(T u)
{
	register int count = 0;
	register int size = sizeof(T)*bits_in_byte;
	for(int i = size-1; i>=0; i--)
	{ 	count++;
		if((u&(1<<i))) cout << 1;
			else cout << 0;
		if(count==8){cout<<' '; count = 0;}
	}
	cout<<'\n';
}

struct Struct8bit{
	//S8b
	//представляет доступ к каждому биту байта
	//физически старший бит записывается в конце
	//так что нумерация в обратном порядке
	uint8_t a8:1;
	uint8_t a7:1;
	uint8_t a6:1;
	uint8_t a5:1;
	uint8_t a4:1;
	uint8_t a3:1;
	uint8_t a2:1;
	uint8_t a1:1;
};

ostream& operator<<(ostream &os, Struct8bit &sb8)
{		//обеспечивает возможность печати Struct8bit 
		//аналогично встроенным типам в формате cout<<sb8;
		os	<<'{'
			<<(bool)sb8.a1
			<<(bool)sb8.a2
			<<(bool)sb8.a3
			<<(bool)sb8.a4
			<<(bool)sb8.a5
			<<(bool)sb8.a6
			<<(bool)sb8.a7
			<<(bool)sb8.a8
			<<'}';
		return os;
}
	
union byteUnion{
	/*объединение позволяющее обращаться 
	к одной и той же области памяти либо 
	как к числу либо как к структуре*/
	//data
	Struct8bit byte;
	uint8_t u8t;
	//functions
	byteUnion()
	{
		cout<<"byteUnion() default constructor\n";
	}
	byteUnion(uint8_t i)
	{
		u8t = i;
		cout<<"byteUnion(uint8_t i) argument constructor\n";
	}
	byteUnion(const byteUnion &other)
	{
		u8t = other.u8t;
		cout<<"byteUnion(const byteUnion &other) copy constructor\n";
	}
	byteUnion& operator=(char i)
	{
		u8t=i;
		return *this;
	}
	const bool operator[](int i)
	{
		switch(i){
				case 1:
					return byte.a1;
					break;
				case 2:
					return byte.a2;
					break;
				case 3:
					return byte.a3;
					break;
				case 4:
					return byte.a4;
					break;
				case 5:
					return byte.a5;
					break;
				case 6:
					return byte.a6;
					break;
				case 7:
					return byte.a7;
					break;
				case 8:
					return byte.a8;
					break;
				default:
					cout<<"Fatal error: byteUnion right indexes is 1-8\n";
					cout<<"You try to access byteUnion["<<i<<"]\n Exiting...\n";
					exit(1);
		}
	}
};



class helper
	/*объект этого класса должен возвращаться из 
	функции индексирования массива битов и 
	содержать в себе ссылку на нужный байт и номер бита в нём.
	при присваивании в левой части объект ставит в 
	соответствующий байт единицу или ноль, при присваиваниии 
	в правой части возвращает булево значение*/
{
	Struct8bit *byte;
	int pos_in_word;
public:
	helper(int piw  = 0, Struct8bit *s = 0){
		byte = s;
		pos_in_word = piw;
	}
	void setup(int piw, Struct8bit *s){
		byte = s;
		pos_in_word = piw;
	}
	bool operator()(){
		switch(pos_in_word){
				case 0:
					return (*byte).a1;
					break;
				case 1:
					return (*byte).a2;
					break;
				case 2:
					return (*byte).a3;
					break;
				case 3:
					return (*byte).a4;
					break;
				case 4:
					return (*byte).a5;
					break;
				case 5:
					return (*byte).a6;
					break;
				case 6:
					return (*byte).a7;
					break;
				case 7:
					return (*byte).a8;
					break;
				default:
					cout<<"Fatal error in helper: byteword out of border\n";
					exit(1);
		}
	}
	helper &operator=(bool b)
	{
		switch(pos_in_word){
				case 0:
					(*byte).a1 = b;
					break;
				case 1:
					 (*byte).a2 = b;
					break;
				case 2:
					 (*byte).a3 = b;
					break;
				case 3:
					 (*byte).a4 = b;
					break;
				case 4:
					 (*byte).a5 = b;
					break;
				case 5:
					 (*byte).a6 = b;
					break;
				case 6:
					 (*byte).a7 = b;
					break;
				case 7:
					 (*byte).a8 = b;
					break;
				default:
					cout<<"Fatal error in helper: byteword out of border\n";
					exit(1);
		}
	}
	friend ostream &operator<<(ostream& os, helper &hp){return os<<hp();}
};

class bitearray{
	byteUnion * bits;
	helper hp;
	int nwords;
	int pos_in_words_array, pos_in_word;
public:
	bitearray(){bits = 0; nwords = pos_in_words_array = pos_in_word = 0; cout<<"bitearray default constructor\n";}
	bitearray(int nbits);
	bitearray(const bitearray &other);
	~bitearray();
	byteUnion& operator[](int i){
		if(0<i||i<nwords)
		{
			return bits[i];
		}
		else
		{
			cout<<"Error: arry size is 0 - "<<nwords-1<<" i = "<<i<<'\n';
			exit(1);
		}
	}
	helper &bitaccess(int i){
		hp.setup(i%8, &(bits[i/8].byte));
		return hp;
	} 
};

bitearray::bitearray(int nbits)
{
	if(nbits%bits_in_byte==0){
		nwords = nbits/bits_in_byte;
	}else{
		nwords = nbits/bits_in_byte+1;
	}
	bits = new byteUnion[nwords];
	pos_in_words_array=pos_in_word=0;
	cout<<"bitearray constructor with argument\n";
}
bitearray::~bitearray()
{
	delete bits;
	cout<<"bitearray destructor\n";
}
bitearray::bitearray(const bitearray &other)
{
	nwords				=	other.nwords;
	pos_in_word			=	other.pos_in_word;
	pos_in_words_array	=	other.pos_in_words_array;
	if(nwords>0)
	{
		bits			= 	new byteUnion[nwords];
	}
	for(int i = 0; i<nwords; i++)
	{
		bits[i].u8t		=	other.bits[i].u8t; 
	}
	cout<<"bitearray copy constructor\n";
	
}

int main(int argv, char* argc[])
{ 
	d_bin(1);
	
	bitearray ba(8*32), ba2;
	bitearray ba3 = ba2;
	int j = 0;
	
	for(int i = 0; i<32; i++)
	{
		ba[i] = (char)(128+i);
	}
	for(int i = 0; i<32; i++)
	{
		cout<<ba[i].u8t<<":"<<ba[i].byte;
	}
	cout<<'\n';
	for(int i = 0; i<32*8; i++)
	{
		//ba.bitaccess(i) = i%2;
	}
	for(int i = 0; i<32; i++)
	{	cout<<'{';
		for(int j = 1;j<=8; j++){ 
			cout<<ba[i][j];
		}
		cout<<'}';
	}
	cout<<'\n';
	
	
	return 0;
}