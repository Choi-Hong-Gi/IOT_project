package study.exception.java;

public class ExceptionThrows {

	public void method1() {
		
		try {
			method2();
		}catch(ClassNotFoundException e){
			//던져진 예외처리
			System.out.println("클래스가 존재하지 않습니다.");
		}
		
	}
	
	
	public void method2() throws ClassNotFoundException {
		
		Class clazz = Class.forName("java.lang.String2");
		//예외발생
		
	}	
	
	
	public static void main(String[] args) {
	
		ExceptionThrows t1 = new ExceptionThrows();
		t1.method1();
		
	}
}
