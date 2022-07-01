package study.collection.java;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

public class CollectionEx {

	static void printList(LinkedList<String> I) {
		Iterator<String> iterator = I.iterator();
		while(iterator.hasNext()) {
			String e = iterator.next();
			String seperator;
			if(iterator.hasNext()) {
				seperator = "->";
			}
			else
				seperator = "\n";
			
			System.out.print(e + seperator);
			
		}
	}
	
	public static void main(String[] args) {
		LinkedList<String> myList = new LinkedList<>();
		
		myList.add("트랜스포머");
		myList.add("스타워즈");
		myList.add("매트릭스");
		myList.add(0, "터미네이터");
		myList.add(2, "아바타");
		myList.add(3, "해리포터");
		myList.add(1, "ㅇㅇ");
		
		
		Collections.sort(myList);
		printList(myList);
		
		Collections.reverse(myList);
		printList(myList);
		
		int index = Collections.binarySearch(myList, "스타워즈")+1;
		System.out.println("아바타는 " + index + " 번째 요소입니다.");
		
	}

}
