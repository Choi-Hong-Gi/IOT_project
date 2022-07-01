package study.exception.java;

abstract class MyPoint {
	int x,y;
	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	
	protected abstract void move(int x, int y); //새 좌표로 이동
	protected abstract void reverse(); //(x,y)에서 (y,x)로 변경
	protected void show() {
		System.out.println( x + ", "+ y);
	};
}
