#include<fstream>
#include"graphics.hpp"
#include"widgets.hpp"
#include"window.hpp"
#include"szoveg.hpp"
#include<iostream>
#include"pushbutton.hpp"
#include"dinamikusszoveg.hpp"
#include"menu.hpp"
using namespace genv;
using namespace std;

class mywindow:public window
{
	menu* m1;
	menu* m2;
	p_button* p;
public:
	mywindow()
	{
		std::vector<std::string>v;
		vector<string>s{"2","3","5","7","11","13","17","19","23","31","37","41","43"};
		m1	=new menu(this,10,200,150,75,s);
		m2	=new menu(this,200,200,150,75,v);
		p	=new p_button(this,10,10,30,30,"->",[this](){m2->add(m1->choosen_one());m1->delete_element(m1->choosen_one_index());});
	}
	void save_values(){}
};

int main()
{
	gout.open(400,400);
	gin.timer(1);
	mywindow a;
	a.event_loop();
	return 0;
}
