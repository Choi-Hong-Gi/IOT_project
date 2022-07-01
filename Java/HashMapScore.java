package study.collection.java;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class HashMapScore {
		
	
	public static void main(String[] args) {
		HashMap<String, Integer> javaScore = new HashMap<String, Integer>();
		
		javaScore.put("Ȳ����", 97);
		javaScore.put("���繮", 88);
		javaScore.put("�賲��", 98);
		javaScore.put("�輺��", 97);
		javaScore.put("�ѿ���", 99);
		
		System.out.println("HashMap ��� ����: "+javaScore.size());
		
		Set<String> Keys = javaScore.keySet();
		
		Iterator<String> it = Keys.iterator();
		
		while(it.hasNext()) {
			String name = it.next();
			int score = javaScore.get(name);
			System.out.println(name + " : " + score );
		}
	}

}
