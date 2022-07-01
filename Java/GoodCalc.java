package study.app.java;

import java.util.Scanner;

public class GoodCalc extends Calculator {
	
	@Override
	public int add(int a, int b) {
		return a+b;
	}

	@Override
	public int subtract(int a, int b) {

		return a-b;
	}

	@Override
	public double average(int[] a) {
		int sum = 0;
		for (int i = 0; i < a.length; i++)
			sum += a[i];
		return sum/a.length;
	}

	public static void main(String[] args) {
//		double x = (double)7/10; // Ÿ�� ĳ���� �ʿ���! ���ϸ� �� = 0
//		System.out.println(x);
		
		Scanner scan = new Scanner(System.in);
		
		GoodCalc g1 = new GoodCalc();
		
		System.out.println("�� ���� �Է�>> ");
		int x = scan.nextInt();
		int y = scan.nextInt();
		
		System.out.println("���� ���: " + g1.add(x, y));
		System.out.println("���� ���: " + g1.subtract(x, y));
		
		System.out.println("��� ��: " + g1.average(new int[] {10,20,30}));
		//������� ���� �迭�� �� �ʱ�ȭ
		
	}
	
	
}
