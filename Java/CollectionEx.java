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
		
		myList.add("Ʈ��������");
		myList.add("��Ÿ����");
		myList.add("��Ʈ����");
		myList.add(0, "�͹̳�����");
		myList.add(2, "�ƹ�Ÿ");
		myList.add(3, "�ظ�����");
		myList.add(1, "����");
		
		
		Collections.sort(myList);
		printList(myList);
		
		Collections.reverse(myList);
		printList(myList);
		
		int index = Collections.binarySearch(myList, "��Ÿ����")+1;
		System.out.println("�ƹ�Ÿ�� " + index + " ��° ����Դϴ�.");
		
	}

}
