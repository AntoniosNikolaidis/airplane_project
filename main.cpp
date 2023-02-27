#include <iostream>
#include "plane.h"

using namespace std;

int main(){
	plane *p=new plane();
	security_employee *se = new security_employee();
	maintenance_employee *me = new maintenance_employee();
	cleaning_employee *ce = new cleaning_employee();
	employee *e1=se;
	employee *e2=me;
	employee *e3=ce;
	p->process(e1);
	p->process(e2);
	p->process(e3);
	e1->report();
	e2->report();
	e3->report();
	if(p->get_all())
		cout<<"  Plane ready to take off!\n"<<endl;
	cout<<p->to_string().get_string()<<"\n"<<endl;
	clone_enrypt_and_print(p);
	delete se;
	delete me;
	delete ce;
	delete p;
}
