package study.collection.java;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class HashMapScore {
		
	
	public static void main(String[] args) {
		HashMap<String, Integer> javaScore = new HashMap<String, Integer>();
		
		javaScore.put("황기태", 97);
		javaScore.put("이재문", 88);
		javaScore.put("김남윤", 98);
		javaScore.put("김성동", 97);
		javaScore.put("한원선", 99);
		
		System.out.println("HashMap 요소 개수: "+javaScore.size());
		
		Set<String> Keys = javaScore.keySet();
		
		Iterator<String> it = Keys.iterator();
		
		while(it.hasNext()) {
			String name = it.next();
			int score = javaScore.get(name);
			System.out.println(name + " : " + score );
		}
	}

}
