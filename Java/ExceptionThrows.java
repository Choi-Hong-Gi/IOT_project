package study.exception.java;

public class ExceptionThrows {

	public void method1() {
		
		try {
			method2();
		}catch(ClassNotFoundException e){
			//������ ����ó��
			System.out.println("Ŭ������ �������� �ʽ��ϴ�.");
		}
		
	}
	
	
	public void method2() throws ClassNotFoundException {
		
		Class clazz = Class.forName("java.lang.String2");
		//���ܹ߻�
		
	}	
	
	
	public static void main(String[] args) {
	
		ExceptionThrows t1 = new ExceptionThrows();
		t1.method1();
		
	}
}
