package study.collection.java;

import java.util.Vector;

public class VectorStudy {
	public static void main(String[] args) {
		
		Vector<Integer> V = new Vector<>();
		V.add(5);
		V.add(4);
		V.add(-1);
		
		V.add(2, 100);
		
		System.out.println("벡터 내 요소 객체 수: " + V.size());
		System.out.println("벡터 현재 용량: " + V.capacity());
		
		//벡터 출력
		for (int i = 0; i < V.size(); i++) {
			System.out.println(i+" 번째:" + V.get(i));
		}
		
		int sum = 0;
		
		for (int i = 0; i < V.size(); i++) {
			sum += V.elementAt(i);
		}
		System.out.println("전체 합: " + sum);
	}

}
