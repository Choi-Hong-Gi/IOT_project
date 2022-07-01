package study.collection.java;

import java.util.HashMap;
import java.util.Scanner;

public class CollectionMission2 {

	public static void main(String[] args) {
		HashMap<String, Integer> person = new HashMap<>();
		
		
		Scanner scan = new Scanner(System.in);
		
		for (int i = 0; i < 2; i++) {
			
			System.out.print("나라 이름과 인구 10번 입력.(예: Korea 5000(만)) >> ");
			String country = scan.next();
			int population  = scan.nextInt();
			
			person.put(country, population);
		}
		
		for(;;) {
			
			System.out.print("인구 검색 >> ");
			String con = scan.nextLine();

			Integer search = person.get(con);

				if(con.equals("그만")) {
					System.out.println("종료합니다.");
					break;
				}

				else if(search != null) {
					System.out.println(con + "의 인구는 " + search);
				}
				else {
					System.out.println(con + "은(는) 없는 나라입니다.");

				}
			}
		scan.close();
		
		
	}

}
