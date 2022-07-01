package study.collection.java;

public class GenericStack2{
	public static void main(String[] args) {
		GStack<String> stringStack = new GStack();
		stringStack.push("seoul");
		stringStack.push("busan");
		stringStack.push("LA");
		
		for (int i = 0; i < 3; i++) {
			System.out.println(stringStack.pop());
		}
		
		GStack<Integer> intStack = new GStack();
		intStack.push(1);
		intStack.push(2);
		intStack.push(3);
		
		for (int i = 0; i < 4; i++) {
			System.out.println(intStack.pop());
		}
	}
	
}