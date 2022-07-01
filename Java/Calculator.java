package com.java.inter;

public class Calculator implements Calculable {
	//                  implements -> 인터페이스 구현
	int tot = 0;
	
	@Override
	public int sum(int[] a) {
		for (int i = 0; i < a.length; i++) {
			tot += a[i];
		}
		return tot;
	}

	@Override
	public int average(int[] a) {
		return tot/a.length;
	}

}
