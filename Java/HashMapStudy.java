package study.collection.java;

import java.util.HashMap;
import java.util.Scanner;

public class HashMapStudy {

	public static void main(String[] args) {
		HashMap<String, String> dic = new HashMap<>();
		
		dic.put("baby", "�Ʊ�");
		dic.put("love", "���");
		dic.put("apple", "���");
		
		Scanner scan = new Scanner(System.in);
		while(true) {
			System.out.print("ã�� ���� �ܾ��? ");
			String eng = scan.nextLine();
			if(eng.equals("exit")) {
				System.out.println("�����մϴ�.");
				break;
			}
			String kor = dic.get(eng);
			if(kor == null) {
				System.out.println(eng + "��(��) ���� �ܾ��Դϴ�.");
			}
			else {
				System.out.println(eng+"��(��) "+kor+ "�Դϴ�.");
			}
		}
		scan.close();
		
	}

}
