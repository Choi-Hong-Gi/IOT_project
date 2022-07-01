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
		
		map.put("황기태",new Student(1, "010-1111-1111"));
		map.put("이재문",new Student(2, "010-2222-2222"));
		map.put("김남윤",new Student(3, "010-3333-3333"));
		
		Scanner scan = new Scanner(System.in);
		
		while(true) {
			System.out.print("검색할 이름?  ");
			String name = scan.nextLine();
			if(name.equals("종료")) {
				System.out.println("종료합니다.");
				break;
			}
			Student idNum = map.get(name);
			if(idNum == null) {
				System.out.println(name + "은(는) 없는 이름입니다.");
			}
			else {
				System.out.println("ID: " + idNum.a + ", 번호: " + idNum.b);
			}
		}
		
		scan.close();
	}

}
