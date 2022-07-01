package study.exception.java;

public class MyColorPoint extends MyPoint {
	String Color = "";
	
	public MyColorPoint(int x, int y, String Color) {
		super(x, y);
		this.Color = Color;
	}

	@Override
	protected void move(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	protected void reverse() {
		int z = y;
		y=x;
		x=z;
	}
	protected void show() {
		System.out.println( x + ", "+ y + ", " + Color);
	};

	public static void main(String[] args) {
		MyPoint p  = new MyColorPoint(2,3,"blue");

		p.move(3,4);

		p.reverse();

		p.show();
	}
}
