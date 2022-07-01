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

		System.out.print("학생 이름, 학과, 학번, 학점 평균을 입력하세요.\n");

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
			System.out.println("이름: "+stdIf.get(i).name);
			System.out.println("학과: "+stdIf.get(i).major);
			System.out.println("학번: "+stdIf.get(i).ID);
			System.out.println("학점평균: "+stdIf.get(i).avgScore);
		}

		while(true) {
			System.out.println("-------------------------------------");
			System.out.print("학생이름 >> ");
			String srcName = scan.next();
			
			if(srcName.equals("그만")) {
				System.out.println("종료합니다.");
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
				System.out.println(srcName + " 학생은 리스트에 없습니다.");
			
		}

		scan.close();

	}

}
