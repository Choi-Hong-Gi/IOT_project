package study.collection.java;

import java.util.Iterator;
import java.util.Vector;

public class IteratorStudy {

	public static void main(String[] args) {
		Vector<Integer> v = new Vector<>();
		
		v.add(1);
		v.add(2);
		v.add(3);
		v.add(2, 100); // 밀어내고 사이에 값 삽입
		
		Iterator<Integer> it = v.iterator(); // 있는데
		
		while(it.hasNext()) {
			int n = it.next();
			System.out.println(n);
		}
		
		it = v.iterator(); // 여기가 없으면 안되는 이유?
		int sum = 0;
		int m = 0;
		while(it.hasNext()) {
			m = it.next();
			sum += m;
		}
		
		System.out.println("벡터에 있는 정수의 합>> "+sum);
	}

}
