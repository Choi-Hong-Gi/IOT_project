package study.collection.java;

import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListStudy {

	public static void main(String[] args) {
		ArrayList<String> a = new ArrayList<>();

		Scanner scan = new Scanner(System.in);

		for (int i = 0; i < 4; i++) {
			System.out.print("이름 입력>> ");
			String s = scan.nextLine();
			a.add(s);
		}

		for (int i = 0; i < a.size(); i++) {
			String name = a.get(i);
			System.out.print("\""+name+"\" ");
		}

		String longgestName = a.get(0);

		for (int i = 0; i < a.size(); i++) {
			if(longgestName.length() < a.get(i).length()) {
				longgestName = a.get(i);
			}
		}
		System.out.println("\n가장 긴 이름은: \""+longgestName+"\"");

		scan.close();
	}

}
