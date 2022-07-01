package multi.thread.java;

public class GettetSetter {

	private int age;
	private String name;
	private int stdID;
	
	public GettetSetter(int age, String name, int stdID) {
		this.setAge(age);
		this.setName(name);
		this.setStdID(stdID);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

	
	//getter, setter
	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getStdID() {
		return stdID;
	}

	public void setStdID(int stdID) {
		this.stdID = stdID;
	}

}
