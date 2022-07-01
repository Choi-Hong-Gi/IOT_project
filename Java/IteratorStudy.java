package study.collection.java;

import java.util.Iterator;
import java.util.Vector;

public class IteratorStudy {

	public static void main(String[] args) {
		Vector<Integer> v = new Vector<>();
		
		v.add(1);
		v.add(2);
		v.add(3);
		v.add(2, 100); // �о�� ���̿� �� ����
		
		Iterator<Integer> it = v.iterator(); // �ִµ�
		
		while(it.hasNext()) {
			int n = it.next();
			System.out.println(n);
		}
		
		it = v.iterator(); // ���Ⱑ ������ �ȵǴ� ����?
		int sum = 0;
		int m = 0;
		while(it.hasNext()) {
			m = it.next();
			sum += m;
		}
		
		System.out.println("���Ϳ� �ִ� ������ ��>> "+sum);
	}

}
