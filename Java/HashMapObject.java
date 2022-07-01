package study.collection.java;

import java.util.HashMap;
import java.util.Scanner;

class Student{
	int a;
	String b;
	Student(int a, String b){
		this.a = a;
		this.b = b;
	}
}

public class HashMapObject {

	
	public static void main(String[] args) {
		HashMap<String, Student> map = new HashMap<String, Student>();
		
		map.put("Ȳ����",new Student(1, "010-1111-1111"));
		map.put("���繮",new Student(2, "010-2222-2222"));
		map.put("�賲��",new Student(3, "010-3333-3333"));
		
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			System.out.print("�˻��� �̸�?  ");
			String name = scan.nextLine();
			if(name.equals("����")) {
				System.out.println("�����մϴ�.");
				break;
			}
			Student idNum = map.get(name);
			if(idNum == null) {
				System.out.println(name + "��(��) ���� �̸��Դϴ�.");
			}
			else {
				System.out.println("ID: " + idNum.a + ", ��ȣ: " + idNum.b);
			}
		}
		
		scan.close();
	}

}
