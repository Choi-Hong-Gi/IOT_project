package study.assignment.java;

import java.util.HashMap;
import java.util.Scanner;

public class CollectionMission2 {

	public static void main(String[] args) {
		HashMap<String, Integer> person = new HashMap<>();
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("���� �̸��� �α� 10�� �Է�.(��: Korea 5000)");
		int i = 0;
		while (true) {
			System.out.print("�����̸�, �α� >> ");
			String country = scan.next();
			if(country.equals("�׸�")) {
				System.out.println("�Է��� �����߽��ϴ�.");
				break;
			}
			int population  = scan.nextInt();
			person.put(country, population);
			i++;
			
			if(i == 10)
				break;
		}
		
		while (true) {
			
			System.out.print("\n�α� �˻� >> ");
			String con = scan.next();

			Integer search = person.get(con);

				if(con.equals("�׸�")) {
					System.out.println("�����մϴ�.");
					break;
				}

				else if(search != null) {
					System.out.println(con + "�� �α��� " + search);
				}
				else {
					System.out.println(con + "��(��) ���� �����Դϴ�.");

				}
			}
		scan.close();
		
		
	}

}