package assinment.java;

import java.util.Scanner;

public class DrawShape {
	
	public run(){
		Scanner scan = new Scanner(System.in);
		System.out.print("[[도형 선택]]\n1. CIRCLE\n2. TRIANGLE\n3. RECTANGLE\n4. EXIT\n\n메뉴선택: ");
		int typeSelect = scan.nextInt();

		if(typeSelect == 4) {
			System.out.println("종료합니다.");
			break;
		}
		else if (typeSelect > 4 || typeSelect < 1) {
			System.out.println("잘못 선택하셨습니다. 다시 입력하세요.\n");
		}

		switch(typeSelect) {

		case 1:
			System.out.print("\n[선택한 도형 CIRCLE의 면적]\n원의 반지름: ");
			int r = scan.nextInt();
			Circle circle1 = new Circle(r);
			System.out.println("\n도형 CIRCLE의 면적: " + circle1.getArea()+ "\n");
			System.out.println("[ CIRCLE 드로잉 ]");
			System.out.print("색상 선택>> (1) Red  (2) Green  (3) Blue  >> ");
			int colorC = scan.nextInt();
			circle1.draw(colorC);
			System.out.println();
			break;

		case 2: 
			System.out.print("\n[선택한 도형 TRIANGLE의 면적]\n너비: ");
			int a = scan.nextInt();
			System.out.print("높이: ");
			int b = scan.nextInt();
			Triangle triangle1 = new Triangle(a, b);
			System.out.println("\n도형 TRIANGLE의 면적: " + triangle1.getArea()+ "\n");
			System.out.println("[ TRIANGLE 드로잉 ]");
			System.out.print("색상 선택>> (1) Red  (2) Green  (3) Blue  >> ");
			int colorT = scan.nextInt();
			triangle1.draw(colorT);
			System.out.println();
			break;

		case 3: 
			System.out.print("\n[선택한 도형 RECTANGLE의 면적]\n가로: ");
			int x = scan.nextInt();
			System.out.print("세로: ");
			int y = scan.nextInt();
			Rectangle rectangle1 = new Rectangle(x, y);
			System.out.println("\n도형 TRIANGLE의 면적: " + rectangle1.getArea()+ "\n");
			System.out.println("[ RECTANGLE 드로잉 ]");
			System.out.print("색상 선택>> (1) Red  (2) Green  (3) Blue  >> ");
			int colorR = scan.nextInt();
			rectangle1.draw(colorR);
			System.out.println();
			break;
	}

	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			
				try {
					while(true) {
					run();
					}
				}
				catch (Exception e) {
					System.out.println("잘못된 입력입니다.");
					run();
				}
			}
			
			scan.close();
		}
	}

}
