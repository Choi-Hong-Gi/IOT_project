package com.java.inter;

class TmpCalc implements Calculable{
	
	@Override
	public int average(int[] a) {
		return 100;
	}
	
	@Override
	public int sum(int[] a) {
		return 89;
	}
	
}

public class UserTest {

	public static void main(String[] args) {
//		TmpCalc c1 = new TmpCalc();
//		int[] arr = {80,90,87,92,91};
//		System.out.println("ÇÕ: " + c1.sum(arr));
//		System.out.println("Æò±Õ : " + c1.average(arr));
		// Å×½ºÆ®
		
		
		Calculator c1 = new Calculator();
		int[] arr = {80,90,87,92,91};
		System.out.println("ÇÕ: " + c1.sum(arr));
		System.out.println("Æò±Õ : " + c1.average(arr));
	}

}
