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
	// 클래스 오버라이드 toString() -> 헥사데시멀 해쉬 코드를 변환

	
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
