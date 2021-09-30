#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
using namespace std;
class Worker {
	protected:
		string fullname;
		unsigned int age;
		float experience;
	public:
	    void set_fullname(string name){
			fullname=name;
		}
		string get_fullname() const {
			return fullname;
		}
		void set_age(unsigned int years){
			age=years;
		}
		unsigned int get_age() const {
			return age;
		}
		void set_experience(float expr){
			experience=expr;
		}
		float get_experience() const {
			return experience;
		}
		virtual void showworkerinfo() const =0;	
};
class Driver: public Worker{
	private:
		string licencenumber, category;
	public:
		void set_licencenumber(string licence){
			licencenumber=licence;
		}
		string get_licencenumber() const {
			return licencenumber;
		}
		void set_category(string cat){
			category=cat;
		}
		string get_category() const {
			return category;
		}
		void showworkerinfo() const override{
			cout<<"|"<<'\t'<<fullname<<'\t'<<"|"<<'\t'<<age<<'\t'<<"|"<<'\t'<<experience<<'\t'<<"|"<<'\t'<<licencenumber<<'\t'<<"|"<<'\t'<<category<<'\t'<<"|"<<endl;
		}
};
class Staff: public Worker{
	protected:
		int category;
	public:
		void set_category(int cat){
			category=cat;
		}
		int get_category() const {
			return category;
		}
		void showworkerinfo() const override{
			cout<<"|"<<'\t'<<fullname<<'\t'<<"|"<<'\t'<<age<<'\t'<<"|"<<'\t'<<experience<<'\t'<<"|"<<'\t'<<category<<'\t'<<"|"<<endl;
		}
};
class Welder: public Staff{
	private:
		int level;
	public:
		void set_level(int lev){
			level=lev;
		}
		int get_level() const {
			return level;
		}
		void showworkerinfo() const override{
			cout<<"|"<<'\t'<<fullname<<'\t'<<"|"<<'\t'<<age<<'\t'<<"|"<<'\t'<<experience<<'\t'<<"|"<<'\t'<<category<<'\t'<<"|"<<'\t'<<level<<'\t'<<"|"<<endl;
		}
};
class Brigadier: public Worker{
	public:
		void showworkerinfo() const override{
			cout<<"|"<<'\t'<<fullname<<'\t'<<"|"<<'\t'<<age<<'\t'<<"|"<<'\t'<<experience<<'\t'<<"|"<<endl;
		}
};
class Master: public Brigadier{
};
class Head: public Brigadier{
};
class Garage{
	private:
		float area;
	public:
		void set_area(float m2){
			area=m2;
		}
		float get_area() const {
			return area;
		}		
};
class Vehicle {
    protected:
		string brand;
		string color;
		string number;
		unsigned int year_of_production;
		float petrol;
		vector<Driver*> driver_;
	public:
		void set_brand(string brandname){
			brand=brandname;
		}
		string get_brand() const {
			return brand;
		}
		void set_color(string colour){
			color=colour;
		}
		string get_color() const {
			return color;
		}
		void set_number(string nmb){
			number=nmb;
		}
		string get_number()const{
			return number;
		}
		void set_year_of_production(unsigned int year){
			year_of_production=year;
		}
		unsigned int get_year_of_production()const{
			return year_of_production;
		}
		void set_petrol(float ptrl){
			petrol=ptrl;
		}
		float get_petrol()const{
			return petrol;
		}
          void add_driver(Driver* driver) {
          driver_.push_back(driver);
          }
          void show_driver(){
          	for(int i=0;i<driver_.size();i++){
          		cout<<"|\t"<<driver_[i]->get_fullname()<<"\t|\t"<<driver_[i]->get_licencenumber()<<"\t|\t\n";
			}
	
		}
		virtual void showcarinfo()const=0;
};
class PublicTransport: public Vehicle{
	protected:
	    unsigned int passengerseats;	
	public:
	    void set_passengersseats(unsigned int seats){
			passengerseats=seats;
		}
		unsigned int get_passengerseats()const{
			return passengerseats;
		}	
};
class Bus: public PublicTransport{
	private:
		string route;
	public:
		void set_route(string rout){
			route=rout;
		}
		string get_route()const{
			return route;
		}
		void showcarinfo()const override{
			cout<<"|"<<'\t'<<number<<'\t'<<"|"<<'\t'<<color<<'\t'<<"|"<<'\t'<<brand<<'\t'<<"|"<<'\t'<<year_of_production<<'\t'<<"|"<<'\t'<<petrol<<'\t'<<"|"<<'\t'<< passengerseats<<'\t'<<"|"<<'\t'<<route<<'\t'<<"|"<<endl;
		}
};	
class Taxi: public PublicTransport{
	private:
		float kg;	
	public:
		void set_kg(float kh){
			kg=kh;
		}
		float get_kg()const{
			return kg;
		}
		void showcarinfo()const override{
			cout<<"|"<<'\t'<<number<<'\t'<<"|"<<'\t'<<color<<'\t'<<"|"<<'\t'<<brand<<'\t'<<"|"<<'\t'<<year_of_production<<'\t'<<"|"<<'\t'<<petrol<<'\t'<<"|"<<'\t'<< passengerseats<<'\t'<<"|"<<'\t'<<kg<<'\t'<<"|"<<endl;
		}
};
class TouristicCoach: public PublicTransport{
	private:
		float moneyperhour;
	public:
		void set_moneyperhour(float money){
			moneyperhour=money;
		}
		float get_moneyperhour()const{
			return moneyperhour;
		}
		void showcarinfo()const override{
			cout<<"|"<<'\t'<<number<<'\t'<<"|"<<'\t'<<color<<'\t'<<"|"<<'\t'<<brand<<'\t'<<"|"<<'\t'<<year_of_production<<'\t'<<"|"<<'\t'<<petrol<<'\t'<<"|"<<'\t'<< passengerseats<<'\t'<<"|"<<'\t'<<moneyperhour<<'\t'<<"|"<<endl;
		}
};
class Truck: public Vehicle{
	protected:
		float tons;
	public:
		void set_tons(float ton){
			tons=ton;
		}
		float get_tons()const{
			return tons;
		}
		void showcarinfo()const override{
			cout<<"|"<<'\t'<<number<<'\t'<<"|"<<'\t'<<color<<'\t'<<"|"<<'\t'<<brand<<'\t'<<"|"<<'\t'<<year_of_production<<'\t'<<"|"<<'\t'<<petrol<<'\t'<<"|"<<'\t'<<tons<<'\t'<<"|"<<endl;
		}
};
class AuxiliaryTransport: public Truck{
	private:
		float length, width;
	public:
		void set_length(float m){
			length=m;
		}
		float get_length()const{
			return length;
		}
		void set_width(float m){
			width=m;
		}
		float get_width()const{
			return width;
		}
		void showcarinfo()const override{
			cout<<"|"<<'\t'<<number<<'\t'<<"|"<<'\t'<<color<<'\t'<<"|"<<'\t'<<brand<<'\t'<<"|"<<'\t'<<year_of_production<<'\t'<<"|"<<'\t'<<petrol<<'\t'<<"|"<<'\t'<<tons<<'\t'<<"|"<<'\t'<<length<<'\t'<<"|"<<'\t'<<width<<'\t'<<"|"<<endl;
		}
};
void cin_string(string& str,ifstream& file,int size=256,char delim='|'){
	str="";
	getline(file,str,delim);
}
void cin_float(double& f,ifstream& file,char delim='|',int size=256){
    char* cstr= new char[size];
    file.getline(cstr,size,delim); 
    f=atof(cstr); 
    delete[] cstr; 
} 
void cin_int(int& f,ifstream& file,char delim='|',int size=256){
    char* cstr= new char[size]; 
    file.getline(cstr,size,delim); 
    f=atoi(cstr); 
    delete[] cstr;	
}
int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  SetConsoleTitle("Курсова робота студентки групи ІП-20-2 Кашуби Наталії");
  cout << " ___________________________________________________________________"<<endl;
  cout << "| База даних автопідприємства                                       |"<<endl;
  cout << " ___________________________________________________________________"<<endl;
  cout << "| Види запитів:                                                     |"<<endl;
  cout << "|              [1]Перегляд даних про автопарк                       |"<<endl;
  cout << "|              [2]Перегляд розподілу автобусів по маршрутах         |"<<endl;
  cout << "|              [3]Перегляд списку і кількості водіїв                |"<<endl;
  cout << "|              [4]Перегляд даних про об'єкти гаражного господарства |"<<endl;
  cout << " ___________________________________________________________________"<<endl;
  vector<Bus> buses;
  vector<Taxi> taxis;
  vector<TouristicCoach> coaches;
  vector<Truck> trucks;
  vector<AuxiliaryTransport> auxiliaries;
  vector<Garage> garages;
  vector<Driver> drivers;
  vector<Staff> staff;
  vector<Welder> welders;
  vector<Brigadier> brigadiers;
  vector<Master> masters;
  vector<Head> heads;
  string carnumber, carcolor, carbrand, carroute, personname, personlicence, personcategory;
  int caryear, carseat, personage, npersoncategory, personlevel;
  double carpetrol, carkg, carmoney, carton, carlength, carwidth, cararea, personexp;
  ifstream fbus("buses.txt");
  if(!fbus.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про маршрутні автобуси, не знайдено."<<endl; 
  }
  while(!fbus.eof()){
  	cin_string(carnumber,fbus);
  	cin_string(carcolor,fbus);
    cin_string(carbrand,fbus);
    cin_int(caryear,fbus);
    cin_float(carpetrol,fbus);
    cin_int(carseat,fbus);
    cin_string(carroute,fbus);
    Bus bus;
    bus.set_number(carnumber);
	bus.set_color(carcolor);
	bus.set_brand(carbrand);
	bus.set_year_of_production(caryear);
	bus.set_petrol(carpetrol);
	bus.set_passengersseats(carseat);
	bus.set_route(carroute);
	buses.push_back(bus);
  } 
  fbus.close();
  ifstream ftaxi("taxis.txt");
  if(!ftaxi.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про таксі, не знайдено."<<endl; 
  }
  while(!ftaxi.eof()){
  	cin_string(carnumber,ftaxi);
  	cin_string(carcolor,ftaxi);
    cin_string(carbrand,ftaxi);
    cin_int(caryear,ftaxi);
    cin_float(carpetrol,ftaxi);
    cin_int(carseat,ftaxi);
    cin_float(carkg,ftaxi);
    Taxi taxi;
    taxi.set_number(carnumber);
	taxi.set_color(carcolor);
	taxi.set_brand(carbrand);
	taxi.set_year_of_production(caryear);
	taxi.set_petrol(carpetrol);
	taxi.set_passengersseats(carseat);
	taxi.set_kg(carkg);
	taxis.push_back(taxi);
  } 
  ftaxi.close();
  ifstream fcoach("coaches.txt");
  if(!fcoach.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про туристичні автобуси, не знайдено."<<endl; 
  }
  while(!fcoach.eof()){
  	cin_string(carnumber,fcoach);
  	cin_string(carcolor,fcoach);
    cin_string(carbrand,fcoach);
    cin_int(caryear,fcoach);
    cin_float(carpetrol,fcoach);
    cin_int(carseat,fcoach);
    cin_float(carmoney,fcoach);
    TouristicCoach coach;
    coach.set_number(carnumber);
	coach.set_color(carcolor);
	coach.set_brand(carbrand);
	coach.set_year_of_production(caryear);
	coach.set_petrol(carpetrol);
	coach.set_passengersseats(carseat);
	coach.set_moneyperhour(carmoney);
	coaches.push_back(coach);
  }  
  fcoach.close();
  ifstream ftruck("trucks.txt");
  if(!ftruck.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про вантажівки, не знайдено."<<endl; 
  }
  while(!ftruck.eof()){
  	cin_string(carnumber,ftruck);
  	cin_string(carcolor,ftruck);
    cin_string(carbrand,ftruck);
    cin_int(caryear,ftruck);
    cin_float(carpetrol,ftruck);
    cin_float(carton,ftruck);
    Truck truck;
    truck.set_number(carnumber);
	truck.set_color(carcolor);
	truck.set_brand(carbrand);
	truck.set_year_of_production(caryear);
	truck.set_petrol(carpetrol);
	truck.set_tons(carton);
	trucks.push_back(truck);
  } 
  ftruck.close();
  ifstream fauxiliary("auxiliary.txt");
  if(!fauxiliary.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про допоміжний транспорт, не знайдено."<<endl; 
  }
  while(!fauxiliary.eof()){
  	cin_string(carnumber,fauxiliary);
  	cin_string(carcolor,fauxiliary);
    cin_string(carbrand,fauxiliary);
    cin_int(caryear,fauxiliary);
    cin_float(carpetrol,fauxiliary);
    cin_float(carton,fauxiliary);
    cin_float(carlength,fauxiliary);
    cin_float(carwidth,fauxiliary);
    AuxiliaryTransport auxiliary;
    auxiliary.set_number(carnumber);
	auxiliary.set_color(carcolor);
	auxiliary.set_brand(carbrand);
	auxiliary.set_year_of_production(caryear);
	auxiliary.set_petrol(carpetrol);
	auxiliary.set_tons(carton);
	auxiliary.set_length(carlength);
	auxiliary.set_width(carwidth);
	auxiliaries.push_back(auxiliary);
  }  
  fauxiliary.close();
  ifstream fgarage("garages.txt");
  if(!fgarage.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про об'єкти гаражного господарства, не знайдено."<<endl; 
  }
  while(!fgarage.eof()){
    cin_float(cararea,fgarage);
    Garage garage;
    garage.set_area(cararea);
    garages.push_back(garage);
  }  
  fgarage.close();
  ifstream fdriver("drivers.txt");
  if(!fdriver.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про водіїв, не знайдено."<<endl; 
  }
  while(!fdriver.eof()){
  	cin_string(personname,fdriver);
  	cin_int(personage,fdriver);
    cin_float(personexp,fdriver);
    cin_string(personlicence,fdriver);
    cin_string(personcategory,fdriver);
    Driver driver;
    driver.set_fullname(personname);
    driver.set_age(personage);
    driver.set_experience(personexp);
    driver.set_licencenumber(personlicence);
    driver.set_category(personcategory);
    drivers.push_back(driver);
  }   
  fdriver.close();
  ifstream fstaff("staff.txt");
  if(!fstaff.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про обслуговуючий персонал, не знайдено."<<endl; 
  }
  while(!fstaff.eof()){
  	cin_string(personname,fstaff);
  	cin_int(personage,fstaff);
    cin_float(personexp,fstaff);
    cin_int(npersoncategory,fstaff);
    Staff staf;
    staf.set_fullname(personname);
    staf.set_age(personage);
    staf.set_experience(personexp);
    staf.set_category(npersoncategory);
    staff.push_back(staf);
  }  
  fstaff.close();
  ifstream fwelder("welders.txt");
  if(!fwelder.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про слюсарів, не знайдено."<<endl; 
  }
  while(!fwelder.eof()){
  	cin_string(personname,fwelder);
  	cin_int(personage,fwelder);
    cin_float(personexp,fwelder);
    cin_int(npersoncategory,fwelder);
    cin_int(personlevel,fwelder);
    Welder welder;
    welder.set_fullname(personname);
    welder.set_age(personage);
    welder.set_experience(personexp);
    welder.set_category(npersoncategory);
    welder.set_level(personlevel);
    welders.push_back(welder);
  }  
  fwelder.close();
  ifstream fbrigadier("brigadiers.txt");
  if(!fbrigadier.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про бригадирів, не знайдено."<<endl; 
  }
  while(!fbrigadier.eof()){
  	cin_string(personname,fbrigadier);
  	cin_int(personage,fbrigadier);
    cin_float(personexp,fbrigadier);
    Brigadier brigadier;
    brigadier.set_fullname(personname);
    brigadier.set_age(personage);
    brigadier.set_experience(personexp);
    brigadiers.push_back(brigadier);
  }   
  fbrigadier.close();
  ifstream fmaster("masters.txt");
  if(!fmaster.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про майстрів, не знайдено."<<endl; 
  }
  while(!fmaster.eof()){
  	cin_string(personname,fmaster);
  	cin_int(personage,fmaster);
    cin_float(personexp,fmaster);
    Master master;
    master.set_fullname(personname);
    master.set_age(personage);
    master.set_experience(personexp);
    masters.push_back(master);
  } 
  fmaster.close();
  ifstream fhead("heads.txt");
  if(!fhead.is_open ()){ 
  cout<<'\n'<<"Файл, що містить дані про начальників ділянок та цехів, не знайдено."<<endl; 
  }
  while(!fhead.eof()){
  	cin_string(personname,fhead);
  	cin_int(personage,fhead);
    cin_float(personexp,fhead);
    Head head;
    head.set_fullname(personname);
    head.set_age(personage);
    head.set_experience(personexp);
    heads.push_back(head);
  }  
  fhead.close();
  for(int i=0;i<buses.size();i++){
  	for(int j=0;j<3;j++){
  		buses[i].add_driver(&drivers[j]);
	  }
  }
  for(int i=0;i<coaches.size();i++){
  	for(int j=3;j<5;j++){
  		coaches[i].add_driver(&drivers[j]);
	  }
  }
  for(int i=0;i<taxis.size();i++){
  	for(int j=5;j<10;j++){
  		taxis[i].add_driver(&drivers[j]);
	  }
  }
  for(int i=0;i<trucks.size();i++){
  	for(int j=10;j<13;j++){
  		trucks[i].add_driver(&drivers[j]);
	  }
  }
  for(int i=0;i<buses.size();i++){
  	for(int j=13;j<15;j++){
  		auxiliaries[i].add_driver(&drivers[j]);
	  }
  }
  cout<<"Оберіть дію ";
  int action;
  cin>>action;
  switch(action){
  	case 1:
  		cout<<"Маршрутні автобуси"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Колір"<<'\t'<<"|"<<'\t'<<"Марка"<<'\t'<<"|"<<'\t'<<"Рік виробництва "<<'\t'<<"|"<<'\t'<<"л бензину/100 м"<<'\t'<<"|"<<'\t'<<"Кількість місць"<<'\t'<<"|"<<'\t'<<"Маршрут"<<'\t'<<"|"<<'\n';
        cout << " _______________________________________________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<buses.size();i++){
  	    buses[i].showcarinfo();
  	    cout << " _______________________________________________________________________________________________________________________________________________________"<<endl;
        }
        cout<<"Таксі"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Колір"<<'\t'<<"|"<<'\t'<<"Марка"<<'\t'<<"|"<<'\t'<<"Рік виробництва"<<'\t'<<"|"<<'\t'<<"л бензину/100 м"<<'\t'<<"|"<<'\t'<<"Кількість місць"<<'\t'<<"|"<<'\t'<<"Вантажопідйомність (кг)"<<'\t'<<"|"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<taxis.size();i++){
  	    taxis[i].showcarinfo();
  	    cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        }
        cout<<"Туристичні автобуси"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Колір"<<'\t'<<"|"<<'\t'<<"Марка"<<'\t'<<"|"<<'\t'<<"Рік виробництва"<<'\t'<<"|"<<'\t'<<"л бензину/100 м"<<'\t'<<"|"<<'\t'<<"Кількість місць"<<'\t'<<"|"<<'\t'<<"Вартість оренди за 1 год (грн)"<<'\t'<<"|"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<coaches.size();i++){
  	    coaches[i].showcarinfo();
  	    cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        }
        cout<<"Вантажівки"<<endl;
        cout << " _______________________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Колір"<<'\t'<<"|"<<'\t'<<"Марка"<<'\t'<<"|"<<'\t'<<"Рік виробництва"<<'\t'<<"|"<<'\t'<<"л бензину/100 м"<<'\t'<<"|"<<'\t'<<"Вантажопідйомність (т)"<<'\t'<<"|"<<endl;
        cout << " _______________________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<trucks.size();i++){
  	    trucks[i].showcarinfo();
  	    cout << " _______________________________________________________________________________________________________________________________"<<endl;
        }
        cout<<"Допоміжний транспорт"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Колір"<<'\t'<<"|"<<'\t'<<"Марка"<<'\t'<<"|"<<'\t'<<"Рік виробництва"<<'\t'<<"|"<<'\t'<<"л бензину/100 м"<<'\t'<<"|"<<'\t'<<"Вантажопідйомність (т)"<<'\t'<<"|"<<'\t'<<"Довжина "<<"|"<<" Ширина"<<'\t'<<"|"<<endl;
        cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<auxiliaries.size();i++){
  	    auxiliaries[i].showcarinfo();
  	    cout << " _______________________________________________________________________________________________________________________________________________________________"<<endl;
        }
  		break;
  	case 2:
        cout << " _______________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Маршрут"<<'\t'<<"|"<<'\n';
        cout << " _______________________________________________"<<endl;
        for(int i=0;i<buses.size();i++){
  	    cout<<"|"<<'\t'<<buses[i].get_number()<<'\t'<<"|"<<'\t'<<buses[i].get_route()<<'\t'<<"|"<<endl;
  	    cout << " _______________________________________________"<<endl;
        }
  		break;
  	case 3:
  		cout << " _______________________________________________________________________________________________________________________"<<endl;
        cout<<"|"<<'\t'<<"Прізвище та ім'я"<<'\t'<<"|"<<'\t'<<"Вік"<<'\t'<<"|"<<'\t'<<"Досвід роботи"<<'\t'<<"|"<<'\t'<<"Номер ліцензії"<<'\t'<<"|"<<'\t'<<"Категорія"<<'\t'<<"|"<<endl;
        cout << " _______________________________________________________________________________________________________________________"<<endl;
        for(int i=0;i<drivers.size();i++){
  	    drivers[i].showworkerinfo();
  	    cout << " _______________________________________________________________________________________________________________________"<<endl;
        }
        cout<<"Загальне число водіїв автопідприємства: "<<drivers.size()<<"."<<endl;
  		break;
  	case 4:
  		cout<<"Наявність об'єктів гаражного господарства в цілому"<<endl;
  		cout << " _______________________________"<<endl;
  		cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Площа"<<'\t'<<"|"<<endl;
  		cout << " _______________________________"<<endl;
  		for(int i=0;i<garages.size();i++){
  			cout<<"|"<<'\t'<<i+1<<'\t'<<"|"<<'\t'<<garages[i].get_area()<<'\t'<<"|"<<endl;
  			cout << " _______________________________"<<endl;
		  }
		cout<<"Наявність об'єктів гаражного господарства для легкових автомобілів"<<endl;
		cout << " _______________________________"<<endl;
  		cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Площа"<<'\t'<<"|"<<endl;
  		cout << " _______________________________"<<endl;
		for(int i=0;i<garages.size();i++){
			if(garages[i].get_area()<35){
			cout<<"|"<<'\t'<<i+1<<'\t'<<"|"<<'\t'<<garages[i].get_area()<<'\t'<<"|"<<endl;
			cout << " _______________________________"<<endl;	
			}
		}
		cout<<"Наявність об'єктів гаражного господарства для автобусів"<<endl;
		cout << " _______________________________"<<endl;
  		cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Площа"<<'\t'<<"|"<<endl;
  		cout << " _______________________________"<<endl;
		for(int i=0;i<garages.size();i++){
			if(garages[i].get_area()>=35&&garages[i].get_area()<80){
			cout<<"|"<<'\t'<<i+1<<'\t'<<"|"<<'\t'<<garages[i].get_area()<<'\t'<<"|"<<endl;
			cout << " _______________________________"<<endl;	
			}
		}
		cout<<"Наявність об'єктів гаражного господарства для вантажівок"<<endl;
		cout << " _______________________________"<<endl;
  		cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Площа"<<'\t'<<"|"<<endl;
  		cout << " _______________________________"<<endl;
		for(int i=0;i<garages.size();i++){
			if(garages[i].get_area()>=80&&garages[i].get_area()<115){
			cout<<"|"<<'\t'<<i+1<<'\t'<<"|"<<'\t'<<garages[i].get_area()<<'\t'<<"|"<<endl;
			cout << " _______________________________"<<endl;	
			}
		}
		cout<<"Наявність об'єктів гаражного господарства для допоміжного транспорту"<<endl;
		cout << " _______________________________"<<endl;
  		cout<<"|"<<'\t'<<"Номер"<<'\t'<<"|"<<'\t'<<"Площа"<<'\t'<<"|"<<endl;
  		cout << " _______________________________"<<endl;
		for(int i=0;i<garages.size();i++){
			if(garages[i].get_area()>=115){
			cout<<"|"<<'\t'<<i+1<<'\t'<<"|"<<'\t'<<garages[i].get_area()<<'\t'<<"|"<<endl;
			cout << " _______________________________"<<endl;	
			}
		}
  		break;
  	default:
  		cout<<"Ви ввели неправильне значення.";
  }
  
}
