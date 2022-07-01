package study.exception.java;

public class ClassException {

	public static void main(String[] args) {
		try { //forName("java.lang.String2") -> 예외발생해주는 메소드
			Class clazz = Class.forName("java.lang.String");
		} catch (ClassNotFoundException e) {
			// 일반 예외
			System.out.println("존재하지 않는 클래스입니다.");
//			e.printStackTrace();
		}
		System.out.println("해당 클래스의 메타데이터를 정리했습니다.");
		
	}

}
