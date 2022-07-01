package study.exception.java;

import java.util.Scanner;

public class TestException01 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		System.out.print("분자 입력>> ");
		int dividend = scan.nextInt();
		System.out.print("분모 입력>> ");
		int divisor = scan.nextInt();
//		int result = dividend/divisor;
//		System.out.println("결과: " + result);
		
		
		try {
			int result = dividend/divisor;
		
		System.out.println("결과: " + result);
		}
		catch (java.lang.ArithmeticException e) {
			System.out.println("나눗셈에서 분모는 0을 사용할 수 없습니다.");
		}
				
	}

}
