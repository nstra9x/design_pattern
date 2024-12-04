#include <iostream>
#include <string>
using namespace std;

class User {
private:
	string name_;
	int age_;
	string email_;
	string address_;
public:
	User(string name, int age, string email, string address) : name_(name), age_(age), email_(email), address_(address) {}
	~User() = default;
	void show() {
		cout << "Info of user is:\nName: " << name_ << endl << "Age: " << age_ << endl << "Email: " << email_ << endl << "Address: " << address_ << endl << endl;
	}
};

class UserBuilder {
private:
	string name_;
	int age_;
	string email_;
	string address_;

public:
	UserBuilder *setName(string name) {
		name_ = name;
		return this;
	}

	UserBuilder *setAge(int age) {
		age_ = age;
		return this;
	}

	UserBuilder *setEmail(string email) {
		email_ = email;
		return this;
	}

	UserBuilder *setAddress(string address) {
		address_ = address;
		return this;
	}

	User *build() {
		return new User(name_, age_, email_, address_);
	}
};

int main() {
	UserBuilder* people = new UserBuilder();
	User *user = people->setName("tra")->setAge(18)->build();
	user->show();

	User *user2 = UserBuilder().setName("son")->setAge(28)->setEmail("son@gmail.com")->setAddress("ducpho")->build();
	user2->show();
}