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
//		double x = (double)7/10; // 타입 캐스팅 필요함! 안하면 값 = 0
//		System.out.println(x);
		
		Scanner scan = new Scanner(System.in);
		
		GoodCalc g1 = new GoodCalc();
		
		System.out.println("두 정수 입력>> ");
		int x = scan.nextInt();
		int y = scan.nextInt();
		
		System.out.println("합의 결과: " + g1.add(x, y));
		System.out.println("차의 결과: " + g1.subtract(x, y));
		
		System.out.println("평균 값: " + g1.average(new int[] {10,20,30}));
		//선언되지 않은 배열의 값 초기화
		
	}
	
	
}
