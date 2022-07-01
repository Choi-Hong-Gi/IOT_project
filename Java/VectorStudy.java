package study.collection.java;

import java.util.Vector;

public class VectorStudy {
	public static void main(String[] args) {
		
		Vector<Integer> V = new Vector<>();
		V.add(5);
		V.add(4);
		V.add(-1);
		
		V.add(2, 100);
		
		System.out.println("���� �� ��� ��ü ��: " + V.size());
		System.out.println("���� ���� �뷮: " + V.capacity());
		
		//���� ���
		for (int i = 0; i < V.size(); i++) {
			System.out.println(i+" ��°:" + V.get(i));
		}
		
		int sum = 0;
		
		for (int i = 0; i < V.size(); i++) {
			sum += V.elementAt(i);
		}
		System.out.println("��ü ��: " + sum);
	}

}
