package assinment.java;

public class Rectangle extends Shape {
	int a,b;
	
	public Rectangle(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	@Override
	public void draw(int a) {
		if(a>3 || a<1)
			System.out.println("잘못된 입력입니다.");
		switch (a) {
		case 1:this.color = "Red"; break;
		case 2: this.color = "Green"; break;
		case 3: this.color = "Blue"; break;
		}
		System.out.println(color + " color로 RECTANGLE을 그립니다.");
	}

	@Override
	public void setDate() {
		
	}

	@Override
	public double getArea() {
		return a*b;
	}

}
