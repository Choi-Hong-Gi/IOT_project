package study.exception.java;


public class CPoint {
	int a,b;
	String c;
	
	public CPoint(int a, int b) {
		this.a = a;
		this.b = b;
		c ="";
	}
	
	public void show() {
		System.out.println("(" + a + " " + b +" "+ c + ")");
	}
	
	@Override
	public String toString() {
		return "x: "+ a +", y: " + b;
	}
	// Ŭ���� �������̵� toString() -> ��絥�ø� �ؽ� �ڵ带 ��ȯ

	
	public static void main(String[] args) {

			CPoint a, b;
			

			a = new CPoint(2, 3);
			b = new CColorPoint(3, 4, "red");

			a.show();
			b.show();

			System.out.println(a);
			System.out.println(b);
	}
}
