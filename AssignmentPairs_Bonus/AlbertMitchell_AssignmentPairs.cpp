


#include <iostream>
using namespace std;
class Pairs
{

	friend istream& operator >>(istream& ins, Pairs& second);
	friend ostream& operator <<(ostream& outs, const Pairs& second);
public:
	Pairs();
	Pairs(int first, int second);
	Pairs(int first); // second parameter defaults to zero
	//other members and friends
	void set_first(int first);
	int get_first();
	int get_second();
	
private:
	int f;
	int s;
};

int main()
{
	
	
	return 0;
}



Pairs::Pairs()
{
	f = 0;
	s = 0;
}
Pairs::Pairs(int first, int second)
{
	set_first(first);
	
}

Pairs::Pairs(int first)
{
	set_first(first);
	s = 0;

}

void Pairs::set_first(int first)
{
	set_first(first);
}


int Pairs::get_first()
{
	return f;
}

int Pairs::get_second()
{
	return s;
}

istream& operator >>(istream& ins, Pairs& second)
{
	char par;
	ins >> par;
	int x, y;
	ins >> x;
	char comma;
	ins >> comma;
	ins >> y;
	char par2;
	ins >> par2;
	
	second = x;
	s.second = y;
	return ins;
}

ostream& operator <<(ostream& outs, const Pairs& second)
{
	outs << "(" << f.second << ',' << s.second << ")";
}