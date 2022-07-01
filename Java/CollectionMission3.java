package study.assignment.java;

import java.util.ArrayList;
import java.util.Scanner;

class StudentInfo{
	String name;
	String major;
	int ID;
	int avgScore;

	StudentInfo(String name, String major, int ID, int avgScore){
		this.name = name;
		this.major = major;
		this.ID = ID;
		this.avgScore = avgScore;
	}
	
	public String toString() {
		return name+ ", " + major + ", "+ ID + ", " + avgScore;
	}
}

public class CollectionMission3 {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		ArrayList<StudentInfo> stdIf = new ArrayList<StudentInfo>();
		int stdNum = 4;

		System.out.print("�л� �̸�, �а�, �й�, ���� ����� �Է��ϼ���.\n");

		for (int i = 0; i < stdNum; i++) {
			System.out.print(">> ");
			String name = scan.next();
			String major = scan.next();
			int ID = scan.nextInt();
			int avgScore = scan.nextInt();

			stdIf.add(new StudentInfo(name, major, ID, avgScore));
		}


		for (int i = 0; i < stdNum; i++) {
			System.out.println("-------------------------------------");
			System.out.println("�̸�: "+stdIf.get(i).name);
			System.out.println("�а�: "+stdIf.get(i).major);
			System.out.println("�й�: "+stdIf.get(i).ID);
			System.out.println("�������: "+stdIf.get(i).avgScore);
		}

		while(true) {
			System.out.println("-------------------------------------");
			System.out.print("�л��̸� >> ");
			String srcName = scan.next();
			
			if(srcName.equals("�׸�")) {
				System.out.println("�����մϴ�.");
				break;
			}
			
			int cnt = 0;
			for (int i = 0; i < stdNum; i++) {
				cnt++;
				if (stdIf.get(i).name.equals(srcName)) {
					System.out.println(stdIf.get(i).toString());
					cnt = 0;
					break;
				}

			}
			if(cnt == stdNum)
				System.out.println(srcName + " �л��� ����Ʈ�� �����ϴ�.");
			
		}

		scan.close();

	}

}
