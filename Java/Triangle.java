package assinment.java;

public class Triangle extends Shape {
	int a, b;
	
	public Triangle(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	@Override
	public void draw(int a) {
		if(a>3 || a<1)
			System.out.println("�߸��� �Է��Դϴ�.");
		switch (a) {
		case 1:this.color = "Red"; break;
		case 2: this.color = "Green"; break;
		case 3: this.color = "Blue"; break;
		}
		System.out.println(color + " color�� TRIANGLE�� �׸��ϴ�.");
	}

	@Override
	public void setDate() {
		
	}

	@Override
	public double getArea() {
		return area = a*b*(0.5);
	}

}
