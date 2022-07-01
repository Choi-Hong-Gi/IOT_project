package assinment.java;

public abstract class Shape {
	double area;
	String color = "invisible";
	String type;
	
	static final String TYPE1 = "CIRCLE";
	static final String TYPE2 = "TRIANGLE";
	static final String TYPE3 = "RECTANGLE";
	
	public abstract void draw(int a);
	public abstract void setDate();
	public abstract double getArea();
}
