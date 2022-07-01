package study.exception.java;

abstract class MyPoint {
	int x,y;
	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	
	protected abstract void move(int x, int y); //�� ��ǥ�� �̵�
	protected abstract void reverse(); //(x,y)���� (y,x)�� ����
	protected void show() {
		System.out.println( x + ", "+ y);
	};
}
