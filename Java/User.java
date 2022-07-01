package assinment2.java;

public class User {
	String name;
	String type;

	User(String name, String type){
		this.name = name;
		this.type = type;
	}
	public String toString() {
		return type + " " + name;
	}

}

class Student extends User{

	Student(String name, String type) {
		super(name, type);
	}
}
class Staff extends User{

	Staff(String name, String type) {
		super(name, type);
	}
}
class Citizen extends User{

	Citizen(String name, String type) {
		super(name, type);
	}
}