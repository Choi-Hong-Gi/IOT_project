package study.exception.java;

import java.util.Scanner;

public class TestException01 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		System.out.print("���� �Է�>> ");
		int dividend = scan.nextInt();
		System.out.print("�и� �Է�>> ");
		int divisor = scan.nextInt();
//		int result = dividend/divisor;
//		System.out.println("���: " + result);
		
		
		try {
			int result = dividend/divisor;
		
		System.out.println("���: " + result);
		}
		catch (java.lang.ArithmeticException e) {
			System.out.println("���������� �и�� 0�� ����� �� �����ϴ�.");
		}
				
	}

}
