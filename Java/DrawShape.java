package assinment.java;

import java.util.Scanner;

public class DrawShape {
	
	public run(){
		Scanner scan = new Scanner(System.in);
		System.out.print("[[���� ����]]\n1. CIRCLE\n2. TRIANGLE\n3. RECTANGLE\n4. EXIT\n\n�޴�����: ");
		int typeSelect = scan.nextInt();

		if(typeSelect == 4) {
			System.out.println("�����մϴ�.");
			break;
		}
		else if (typeSelect > 4 || typeSelect < 1) {
			System.out.println("�߸� �����ϼ̽��ϴ�. �ٽ� �Է��ϼ���.\n");
		}

		switch(typeSelect) {

		case 1:
			System.out.print("\n[������ ���� CIRCLE�� ����]\n���� ������: ");
			int r = scan.nextInt();
			Circle circle1 = new Circle(r);
			System.out.println("\n���� CIRCLE�� ����: " + circle1.getArea()+ "\n");
			System.out.println("[ CIRCLE ����� ]");
			System.out.print("���� ����>> (1) Red  (2) Green  (3) Blue  >> ");
			int colorC = scan.nextInt();
			circle1.draw(colorC);
			System.out.println();
			break;

		case 2: 
			System.out.print("\n[������ ���� TRIANGLE�� ����]\n�ʺ�: ");
			int a = scan.nextInt();
			System.out.print("����: ");
			int b = scan.nextInt();
			Triangle triangle1 = new Triangle(a, b);
			System.out.println("\n���� TRIANGLE�� ����: " + triangle1.getArea()+ "\n");
			System.out.println("[ TRIANGLE ����� ]");
			System.out.print("���� ����>> (1) Red  (2) Green  (3) Blue  >> ");
			int colorT = scan.nextInt();
			triangle1.draw(colorT);
			System.out.println();
			break;

		case 3: 
			System.out.print("\n[������ ���� RECTANGLE�� ����]\n����: ");
			int x = scan.nextInt();
			System.out.print("����: ");
			int y = scan.nextInt();
			Rectangle rectangle1 = new Rectangle(x, y);
			System.out.println("\n���� TRIANGLE�� ����: " + rectangle1.getArea()+ "\n");
			System.out.println("[ RECTANGLE ����� ]");
			System.out.print("���� ����>> (1) Red  (2) Green  (3) Blue  >> ");
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
					System.out.println("�߸��� �Է��Դϴ�.");
					run();
				}
			}
			
			scan.close();
		}
	}

}
