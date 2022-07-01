package assinment.java;

public class Circle extends Shape {
	double pi = 3.14;
	int r;

	public Circle(int r) {
		this.r = r;
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
		System.out.println(color + " color로 CIRCLE을 그립니다.");
	}

	@Override
	public void setDate() {
		
	}

	@Override
	public double getArea() {
		return r*r*pi;
	}

}
