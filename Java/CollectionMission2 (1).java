package study.collection.java;

import java.util.HashMap;
import java.util.Scanner;

public class CollectionMission2 {

	public static void main(String[] args) {
		HashMap<String, Integer> person = new HashMap<>();
		
		
		Scanner scan = new Scanner(System.in);
		
		for (int i = 0; i < 2; i++) {
			
			System.out.print("���� �̸��� �α� 10�� �Է�.(��: Korea 5000(��)) >> ");
			String country = scan.next();
			int population  = scan.nextInt();
			
			person.put(country, population);
		}
		
		for(;;) {
			
			System.out.print("�α� �˻� >> ");
			String con = scan.nextLine();

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
