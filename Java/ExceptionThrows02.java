package study.exception.java;

public class ExceptionThrows02 {

	public void method1() throws Exception {
		throw new Exception();
	}

	public void method2() throws ClassNotFoundException {
		Class clazz = Class.forName("java.lang.String2");
	}

	public static void main(String[] args) throws Exception {
		ExceptionThrows02 ok = new ExceptionThrows02();
		ok.method1();

	}

}
