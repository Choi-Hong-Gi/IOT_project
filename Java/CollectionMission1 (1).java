package study.collection.java;

import java.util.Scanner;
import java.util.Vector;

public class CollectionMission1 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		Vector<Integer> v = new Vector<>();

		int end = 0;

		while(true) {
			System.out.print("���� �Է�('-1' �Է±���)>> ");
			end = scan.nextInt();
			if(end == -1)
				break;
			else
				v.add(end);
		}

		int max = v.get(0);

		for (int i = 0; i < v.size(); i++) {
			if(max < v.get(i)) {
				max = v.get(i);
			}
		}
		System.out.println("���� ū ��: " + max);
		
	}

}
