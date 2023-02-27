#include <iostream>
#include <string>

class String;

class object{	//abstract
	int id;
public:
	object();
	~object();
	void set_id();
	int get_id();
	virtual bool ob_equal(object&) = 0;
	bool ob_identical(object&);
	String to_string();
	virtual object* create_clone() = 0;	
	
};

class String : public object {
	std::string str;
public:
	String(std::string);
	~String();
	std::string get_string();
	void updateAt(int);
	bool ob_equal(object&);
	String to_string();	
	void s_print();
	object* create_clone();
};

class employee;

class plane_component : public object { //abstract
public:
	plane_component();
	~plane_component();
	virtual bool ready_check() = 0;
	String to_string();
	virtual void process(employee*) = 0;
	object* create_clone();
};

class passenger_compartment : public plane_component {
	passenger_compartment* pc1;
public:
	passenger_compartment();
	~passenger_compartment();
	bool ob_equal(object&);
	bool ready_check();
	String to_string();
	String to_string(passenger_compartment&);
	void process(employee*);
	object* create_clone();
};

class private_compartment : public plane_component {
public:
	private_compartment();
	~private_compartment();
	bool ob_equal(object&);
	bool ready_check();
	String to_string();
	void process(employee*);
	object* create_clone();
};

class equipment_compartment : public private_compartment {
public:
	equipment_compartment();
	~equipment_compartment();
	bool ob_equal(object&);
	bool ready_check();
	String to_string();
	void process(employee*);
	object* create_clone();
};

class cargo_bay : public private_compartment {
	equipment_compartment *ec4;
public:
	cargo_bay();
	~cargo_bay();
	bool ob_equal(object&);
	bool ready_check();
	String to_string();
	void process(employee*);
	object* create_clone();
};

class plane : public object {
	String* title;
	int passenger_cap;
	equipment_compartment *ec1;
	equipment_compartment *ec2;
	equipment_compartment *ec3;
	cargo_bay *cb1;
	passenger_compartment* pc;
	bool ready_check_all;
public:
	plane();
	~plane();
	void ready_check();
	bool ob_equal(object&);
	String to_string();
	void process(employee*);
	bool get_all();
	object* create_clone();
};

class employee : public object{		//abstract
	String* name;
public:
	employee();
	~employee();
	bool ob_equal(object&);
	virtual	void work_on(cargo_bay*) = 0;
	virtual	void work_on(equipment_compartment*) = 0;
	virtual	void work_on(passenger_compartment*) = 0;
	virtual void report() = 0;
	String* get_name();
	String to_string();
	object* create_clone();
};

class security_employee : public employee {
public:
	security_employee();
	~security_employee();
	void work_on(cargo_bay*); 
	void work_on(equipment_compartment*); 
	void work_on(passenger_compartment*);
	void report();  
	String to_string();
	object* create_clone();
};

class maintenance_employee : public employee {
public:
	maintenance_employee();
	~maintenance_employee();
	void work_on(cargo_bay*); 
	void work_on(equipment_compartment*); 
	void work_on(passenger_compartment*);
	void report();
	String to_string();
	object* create_clone();
};

class cleaning_employee : public employee {
public:
	cleaning_employee();
	~cleaning_employee();
	void work_on(cargo_bay*); 
	void work_on(equipment_compartment*); 
	void work_on(passenger_compartment*);
	void report();
	String to_String();
	object* create_clone();
};

void clone_enrypt_and_print(object* obj);
