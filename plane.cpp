#include <iostream>
#include <string>
#include <sstream>
#include "plane.h"
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h> 

using namespace std;

int s_id = 0;

object::object(){
	//cout<<"Object just created!\n"<<endl;
}

object::~object(){
	//cout<<"Object to be destroyed!\n"<<endl;
}

void object::set_id(){
	id=s_id;
	s_id++;
}

int object::get_id(){
	return id;
}

bool object::ob_equal(object& ob){
	if (this->id==ob.id)
		return true;
	else
		return false;
}

bool object::ob_identical(object& ob1){
	if((&(*this))==(&ob1))
		return true;
	else
		return false;
}

String object::to_string(){
	stringstream ss;
	ss<<"object,id="<< id;
	String s(ss.str());
	return s;
}

object* object::create_clone(){
	this->id=id;
}

String::String(std::string st1){
//	cout<<"String just created!\n"<<endl;
	set_id();
	str=st1;
}

String::~String(){
//	cout<<"String to be destroyed!\n"<<endl;
}

string String::get_string(){
	return str;
}

void String::updateAt(int k){
	this->str.replace(k,1,"X");
}

bool String::ob_equal(object& ob){
	
}

String String::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.str;
	ss<<",String,str="<<str<<endl;
	String s(ss.str());
	return s;
}

void String::s_print(){
	cout<<"str is: "<<this->str<<endl;
}

object* String::create_clone(){
	this->str=str;
	return this;
}

plane_component::plane_component(){
	cout<<"Plane component just created!\n"<<endl;
}

plane_component::~plane_component(){
	cout<<"Plane component to be destroyed!\n"<<endl;
}

String plane_component::to_string(){
	stringstream ss;
	ss<<",plane component,";
	String s(ss.str());
	return s;
}

void plane_component::process(employee* em1){

}

object* plane_component::create_clone(){
	
}

int flag=0;

passenger_compartment::passenger_compartment(){
	cout<<"Passenger compartment just created!\n"<<endl;
	set_id();
	if (flag==0){
		flag++;
		pc1 = new passenger_compartment();
	}
}

passenger_compartment::~passenger_compartment(){
	cout<<"Passenger compartment to be destoyed!\n"<<endl;
	if(flag==1){
		flag++;
		delete pc1;
	}
}

bool passenger_compartment::ob_equal(object& ob){
	
}

int cb_check = 0;
int ec_check = 0;
int pc_check = 0;

bool passenger_compartment::ready_check(){
	if(pc_check==2){
		cout<<" Passenger compartment OK!\n"<<endl;
		pc_check=0;
		return true;
	}
	return false;
}

String passenger_compartment::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<plane_component::to_string().get_string();
	ss<<",passenger compartment: pass_comp,";
	ss<<pc1->to_string(*pc1).get_string();
	String s(ss.str());
	return s;
}

String  passenger_compartment::to_string(passenger_compartment& pc2){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<plane_component::to_string().get_string();
	ss<<",passenger compartment: pass_comp";
	String s(ss.str());
	return s;
}

int flag1=0;

void passenger_compartment::process(employee* em1){
	em1->work_on(this);
	if(flag1==0){
		flag1++;
		plane_component *p2=pc1;
		p2->process(em1);
		p2->ready_check();
	}
}

object* passenger_compartment::create_clone(){
	this->pc1=pc1;
	return this;
}

private_compartment::private_compartment(){
	set_id();
	cout<<"Private compartment just created!\n"<<endl;
}

private_compartment::~private_compartment(){
	cout<<"Private compartment to be destroyed!\n"<<endl;
}

bool private_compartment::ob_equal(object& ob){
	
}

bool private_compartment::ready_check(){
	
}

String private_compartment::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<",private compartment,";
	String s(ss.str());
	return s;
}

void private_compartment::process(employee* em1){

}

object* private_compartment::create_clone(){
	
}

equipment_compartment::equipment_compartment(){
	set_id();
	cout<<"Equipment compartment just created!\n"<<endl;
}

equipment_compartment::~equipment_compartment(){
	cout<<"Equipment compartment to be destroyed!\n"<<endl;
}

bool equipment_compartment::ob_equal(object& ob){
	
}

bool equipment_compartment::ready_check(){
	if(ec_check==2){
		cout<<"	Equipment compartment OK!\n"<<endl;
		ec_check=0;
		return true;
	}
	return false;
}

String equipment_compartment::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<plane_component::to_string().get_string();
	ss<<private_compartment::to_string().get_string();
	ss<<",equipment compartment";
	String s(ss.str());
	return s;
}

void equipment_compartment::process(employee* em1){
	em1->work_on(this);
}

object* equipment_compartment::create_clone(){
	
}

cargo_bay::cargo_bay(){
	cout<<"Cargo bay just created!\n"<<endl;
	set_id();
	ec4= new equipment_compartment();	
}

cargo_bay::~cargo_bay(){
	cout<<"Cargo bay to be destroyed!\n"<<endl;
	delete ec4;
}

bool cargo_bay::ob_equal(object& ob){
	
}

bool cargo_bay::ready_check(){
	if(cb_check==3){
		cout<<"	Cargo bay OK!\n"<<endl;
		cb_check=0;
		return true;
	}
	return false;
}

String cargo_bay::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<plane_component::to_string().get_string();
	ss<<private_compartment::to_string().get_string();
	ss<<",cargo bay,";
	ss<<ec4->to_string().get_string();
	String s(ss.str());
	return s;
}

void cargo_bay::process(employee* em1){
	em1->work_on(this);
	plane_component *p = ec4;
	p->process(em1);
	p->ready_check();
}

object* cargo_bay::create_clone(){
	this->ec4=ec4;
	return this;
}

plane::plane():passenger_cap(200){
	cout<<"Plane just created!\n"<<endl;
	title= new String("boyeing");
	ec1= new equipment_compartment();
	ec2= new equipment_compartment();
	ec3= new equipment_compartment();
	cb1= new cargo_bay();
	pc= new passenger_compartment();
	set_id();
}

plane::~plane(){
	cout<<"Plane to be destroyed!\n"<<endl;
	delete title;
	delete ec1;
	delete ec2;
	delete ec3;
	delete cb1;
	delete pc;
}

bool plane::ob_equal(object& ob){
	plane& p=(plane&)ob;
	if (this->title->get_string().compare(p.title->get_string()))
		if(this->passenger_cap==p.passenger_cap)
			if(this->ec1->ob_equal(p))
				if(this->ec2->ob_equal(p))
					if(this->ec3->ob_equal(p))
						if(this->cb1->ob_equal(p))
							if(this->pc->ob_equal(p))
								if(this->ready_check_all==p.ready_check_all)
									return true;
	return false;
}

String plane::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<",plane,title: "<<title->get_string()<<" ,passenger cap="<<passenger_cap;
	ss<<","<<ec1->to_string().get_string()<<","<<ec2->to_string().get_string()<<","<<ec3->to_string().get_string();
	ss<<","<<cb1->to_string().get_string();
	ss<<","<<pc->to_string().get_string();
	String s(ss.str());
	return s;
}

void plane::process(employee* em1){
	flag1=0;
	plane_component *pl1 = cb1;
	pl1->process(em1);
	if(pl1->ready_check())
		ready_check_all=true;
	plane_component *pl2 = ec1;
	pl2->process(em1);
	if(pl2->ready_check())
		ready_check_all=true;
	plane_component *pl3 = ec2;
	pl3->process(em1);
	if(pl3->ready_check())
		ready_check_all=true;
	plane_component *pl4 = ec3;
	pl4->process(em1);
	if(pl4->ready_check())
		ready_check_all=true;
	plane_component *pl5 = pc;
	pl5->process(em1);
	if(pl5->ready_check())
		ready_check_all=true;
}

bool plane::get_all(){
	return ready_check_all;
}

object* plane::create_clone(){
	this->title->create_clone();
	this->passenger_cap=passenger_cap;
	this->ec1->create_clone();
	this->ec2->create_clone();
	this->ec3->create_clone();
	this->cb1->create_clone();
	this->pc->create_clone();
	this->ready_check_all=ready_check_all;
	return this;
}

int flag2=0;

employee::employee(){
	if(flag2==0){
		srand((int)time(0));
		flag2++;
	}
	int k=(rand()%3);
	if(k==0)
		name= new String("nick");
	else if(k==1)
		name= new String("jonh");
	else if(k==2){
		name= new String("mary");
	}
	cout<<"Employee just created!\n"<<endl;
}

employee::~employee(){
	cout<<"Employee to be destroyed!\n"<<endl;
	delete name;
}

bool employee::ob_equal(object& ob){
	employee& e=(employee&)ob;
	if(this->name==e.name)
		return true;
	else
		return false;
}

String* employee::get_name(){
	return name;
}

String employee::to_string(){
	stringstream ss;
	String temp(object::to_string().get_string());
	ss<<temp.get_string();
	ss<<",employee,name: "<<name->get_string();
	String s(ss.str());
	return s;
}

object* employee::create_clone(){
	this->name->create_clone();
	return this;
}

security_employee::security_employee(){
	cout<<"Security employee just created!\n"<<endl;
	set_id();
}

String security_employee::to_string(){
	stringstream ss;
	ss<<employee::to_string().get_string();
	ss<<",security employee\n"<<endl;
	String s(ss.str());
	return s;
}

security_employee::~security_employee(){
	cout<<"Security employee to be destroyed!\n"<<endl;
}

void security_employee::work_on(cargo_bay* cb){
	cb_check++;
}

void security_employee::work_on(equipment_compartment* ec){
	ec_check++;
}

void security_employee::work_on(passenger_compartment* pl){
	pc_check++;
}

void security_employee::report(){
	cout<<"   I am "<<this->get_name()->get_string()<<" and all component are secure!OK!\n"<<endl;
}

object* security_employee::create_clone(){
	
}

maintenance_employee::maintenance_employee(){
	set_id();
	cout<<"Maintenance employee just created!\n"<<endl;
}

maintenance_employee::~maintenance_employee(){
	cout<<"Maintenance employee to be destroyed!\n"<<endl;
}

void maintenance_employee::work_on(cargo_bay* cb){
	cb_check++;
}

void maintenance_employee::work_on(equipment_compartment* ec){
	ec_check++;
}

void maintenance_employee::work_on(passenger_compartment* pl){
	
}

void maintenance_employee::report(){
	cout<<"   I am "<<this->get_name()->get_string()<<" and i have maintenance all the component!OK!\n"<<endl;
}

String maintenance_employee::to_string(){
	stringstream ss;
	ss<<employee::to_string().get_string();
	ss<<",maintenance employee\n"<<endl;
	String s(ss.str());
	return s;
}

object* maintenance_employee::create_clone(){
	
}

cleaning_employee::cleaning_employee(){
	set_id();
	cout<<"Cleaning employee just created!\n"<<endl;
}

cleaning_employee::~cleaning_employee(){
	cout<<"Cleaning employee to be created!\n"<<endl;
}

void cleaning_employee::work_on(cargo_bay* cb){
	cb_check++;
}

void cleaning_employee::work_on(equipment_compartment* ec){
	
}

void cleaning_employee::work_on(passenger_compartment* pl){
	pc_check++;
}

void cleaning_employee::report(){
	cout<<"   I am "<<this->get_name()->get_string()<<" and all component are clean!OK!\n"<<endl;
}

String cleaning_employee::to_String(){
	stringstream ss;
	ss<<employee::to_string().get_string();
	ss<<",cleaning employee\n"<<endl;
	String s(ss.str());
	return s;
}

object* cleaning_employee::create_clone(){
	
}

void clone_enrypt_and_print(object* obj){
	srand((int)time(0));
    object *clone_object=obj->create_clone();
    if(obj->ob_equal(*clone_object)==1)
    	cout<<"Objects are equal\n"<<endl;
    if(obj->ob_identical(*clone_object)==1)
    	cout<<"Objects are identical equal\n"<<endl;
    plane* p=(plane*)obj;
    plane* p2=(plane*)clone_object;
    String *temp;
    temp=new String(p2->to_string().get_string());
	for(int i=0;i<8;i++){
		int k=(rand()%(p2->to_string().get_string().length()));
		temp->updateAt(k);
	}
	stringstream ss;
	ss<<temp->get_string();
	ss<<p->to_string().get_string();
	String s(ss.str());
	cout<<"String length is:"<<s.get_string().length()<<"\n"<<endl;
	int s_length=s.get_string().length();
	if(s_length%2==0)
		cout<<"Middle characters are:"<<s.get_string().at(s_length/2)<<","<<s.get_string().at(s_length/2+1)<<"\n"<<endl;
	else
		cout<<"Middle character is:"<<s.get_string().at(s_length/2)<<"\n"<<endl;
	s.get_string().clear();
	cout<<"New string length is:"<<s.get_string().length()<<"\n"<<endl;
	delete temp;
}
