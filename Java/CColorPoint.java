package study.exception.java;

public class CColorPoint extends CPoint {
	
	public CColorPoint(int a, int b, String color) {
		super(a,b);
		this.c = color;
	}
	public String toString() {
		return "x: "+ a +", y: "+b + "\ncolor: " + c; 
	} // �޼ҵ� �����ε�
}
